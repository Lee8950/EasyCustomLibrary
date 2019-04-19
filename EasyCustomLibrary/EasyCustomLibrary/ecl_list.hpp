#ifndef __ECL_LIST__
#define __ECL_LIST__

#include <vector>

namespace ecl {
	template<typename T>
	class ecl_List {
	private:
		struct Node {
			T Data;
			Node *Next;
			Node *Prev;
		};
		Node *Head, *Last;

		void CreateNewNodeBack() {
			Node *p;
			if (Head == nullptr) {
				Head = new Node;
				Last = Head;
				Head->Next = nullptr;
				Head->Prev = nullptr;
				return;
			}
			p = new Node;
			Last->Next = p;
			p->Prev = Last;
			p->Next = nullptr;
			Last = p;
			p = nullptr;
		}

		void WriteData(T __data) {

		}

	public:

		ecl_List() {
			Head = nullptr;
			Last = nullptr;
		}

		~ecl_List() {
			Node *p;
			while (Head != Last) {
				p = Head;
				Head = Head->Next;
				delete p;
			}
			delete Head;
			Head = nullptr;
			Last = nullptr;
			p = nullptr;
		}

		void PushBack(T __data) {
			CreateNewNodeBack();
			Last->Data = __data;
		}

		bool DeleteByElement(T __ele) {
			Node *p = Head;
			if (Head->Data == __ele) {
				if (Head != Last) {
					Head = Head->Next;
				}
				else {
					Head = nullptr;
					Last = nullptr;
				}
				delete p;
				return true;
			}
			p = p->Next;
			while (p != nullptr) {
				if (p->Data == __ele) {
					if (p->Next != nullptr)
						(p->Next)->Prev = p->Prev;
					(p->Prev)->Next = p->Next;
					delete p;
					p = nullptr;
					return true;
				}
				p = p->Next;
			}
			return false;
		}

		std::vector<T> Read() {
			std::vector<T> temp;
			Node *p = Head;
			while (p != nullptr) {
				temp.push_back(p->Data);
				p = p->Next;
			}
			return temp;
		}

		void debug() {
			Node *p = Head;
			while (p != nullptr) {
				cout << p->Next << endl;
				p = p->Next;
			}
		}
	};
}

#endif