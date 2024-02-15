#ifndef link
#define link
namespace linkedlist{
	struct Node
	{
	public:
		int n;
		std::shared_ptr<Node> next;

		Node(int a) : n{ a }, next{ nullptr } {}
	};

	class linkedList
	{
	private:
		std::shared_ptr<Node> Head;

	public:
		linkedList();
		void insertAtbegin(int x);
		void insertAtlast(int x);
		int getLength();
		void deleteIndex(int index);
		void display();
		void insertAtPos(int index, int value);

	};
}
#endif
