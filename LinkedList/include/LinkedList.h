#ifndef link
#define link
namespace linkedlist{

	template<typename T>
	struct Node
	{
	public:
		T n;
		std::shared_ptr<Node<T>> next;

		Node(T a) : n{ a }, next{ nullptr } {}
	};

	template <typename T>
	class linkedList
	{
	private:
		std::shared_ptr<Node<T>> Head;

	public:
		linkedList()
		{
			std::shared_ptr<Node<T>> head = nullptr;
		}
		linkedList(const std::initializer_list<T>& list)
		{
			for (const T& i : list) {
				insertAtlast(i);
			}
		}

		template<typename T>
		void insertAtbegin(const T& x)
		{
			auto n = std::make_shared<Node<T>>(x);
			if (Head == nullptr)
			{
				Head = n;
				return;
			}
			n->next = Head;
			Head = n;
		}
		template<typename T>
		void insertAtlast(const T& x)
		{
			auto n = std::make_shared<Node<T>>(x);
			if (Head == nullptr)
			{
				Head = n;
				return;
			}
			auto tmp = Head;
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = n;
		}

		int getLength()
		{
			auto count = 1;
			auto tmp = Head;
			while (tmp->next != nullptr)
			{
				count++;
				tmp = tmp->next;
			}
			return count;
		}

		void deleteIndex(unsigned int  UI)
		{
			int count = getLength();
			if (UI == 1)
			{
				Head = Head->next;
				return;
			}
			if (UI == count)
			{
				auto tmp = Head;
				auto tmp1 = Head->next;
				while (tmp1->next != nullptr)
				{
					tmp = tmp->next;
					tmp1 = tmp1->next;
				}
				tmp->next = nullptr;
				return;
			}
			if (UI > 1 && UI < count)
			{
				auto tmp = Head;
				auto tmp1 = Head->next;
				auto count1 = 2;
				while (UI != count1)
				{
					tmp = tmp->next;
					tmp1 = tmp1->next;
					count1++;
				}
				tmp->next = tmp1->next;
				tmp1->next = nullptr;
				return;
			}
			if (UI <= 0 || UI > count)
			{
				std::cout << "Trying to delete invalid node\n";
				return;
			}
		}

		void display()
		{
			auto tmp = Head;
			while (tmp != nullptr)
			{
				std::cout << tmp->n << " -> ";
				tmp = tmp->next;
			}
			std::cout << '\n';
		}

		template<typename T>
		void insertAtPos(unsigned int UI,const T& value)
		{
			auto lng = getLength();
			if (UI < 0 || UI > lng + 1)
			{
				std::cout << "Trying OutOfBound Insertion using insertAtPos()\n";
			}

			if (UI > 1 && UI <= lng)
			{
				auto tmp = Head;
				auto tmp0 = tmp;
				auto cnt = 1;
				while (cnt != UI)
				{
					tmp0 = tmp;
					tmp = tmp->next;
					cnt++;
				}
				auto n = std::make_shared<Node<T>>(value);
				tmp0->next = n;
				n->next = tmp;
				return;
			}

			if (UI == 1)
			{
				insertAtbegin(value);
				return;
			}
			if (UI == lng + 1)
			{
				insertAtlast(value);
				return;
			}
		}


	};
}
#endif
