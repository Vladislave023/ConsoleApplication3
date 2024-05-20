
#include <iostream>
#include <iterator>
#include <cctype>
using namespace std;
//template <typename T>
struct Node {
	char data;
	Node* next;
	Node* prev;

	Node(char val, Node* next = nullptr, Node* prev = nullptr) :
		data(val), next(next), prev(prev){}
	;

};



class ForwardIterator {
	Node* ptr;

public:
	//ForwardIterator(Node* val);
	ForwardIterator(Node* startNode) : ptr(startNode) {}

	char& operator* () {
		return ptr->data;
	}

	ForwardIterator& operator++() {
		ptr = ptr->next;

		while (ptr && !isupper(ptr->data)) {
			ptr = ptr->next;
		}
		return *this;
	}
	bool operator==(const ForwardIterator& other)const {
		return ptr == other.ptr;
	}
	bool operator!=(const ForwardIterator& other) const {
		return !(*this == other);

	}
};


	 
	class List {
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		friend std::ostream& operator <<(std::ostream& os, const Node& node);
		using iterator = ForwardIterator;


		void AddElem(char val) {
			
			if (!head) {
				head = new Node(val);
				tail = head;
				return;
			}
			Node* current = new Node(val, nullptr, nullptr);
			tail->next = current;
			current->prev = tail;
			tail = current;
		}
		iterator begin() {
			return iterator(head);
		}
		iterator end() {
			return iterator(nullptr);
		}

		void PrintList() {
			if (!head) {
				cout << " nothing" << '\n';
				return;
			}

			for (Node* node = head; node != nullptr; node = node->next) {
				cout << node->data << " ";
			}
			cout << '\n';
		}
		void ReverseList() {
			if (!tail) {
				cout << " nothing" << '/n';
				return;
			}
			for (Node* node = tail; node != nullptr; node = node->prev)
				cout << node->data << " ";
			cout << '\n';

		}

		void DeleteList() {
			if (!head) {
				std::cout << "spisok pust" << std::endl;
				return;
			}
			while (head->next != nullptr) {
				Node* nodeDelete = head;
				head = head->next;
				delete nodeDelete;
			}
			delete head;
			head = nullptr;
		}
	};

	int main()
	{
		
		List list1;
		
		list1.AddElem('A');
		list1.AddElem('D');
		list1.AddElem('x');
		list1.AddElem('K');
		list1.AddElem('o');
		list1.AddElem('F');
		list1.AddElem('l');
		list1.AddElem('P');

		//list1.PrintList();
		auto it = list1.begin();
		for (; it != list1.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
		list1.ReverseList();
		list1.DeleteList();
		list1.PrintList();
		return 0;
	}