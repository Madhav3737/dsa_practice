class Node:

    def __init__(self, value):
        self.value = value
        self.next = None

class Linkedlist:

    def __init__(self):
        self.head = None
        self.tail = None

    def __repr__(self):
        pass

    def __contains__(self):
        pass

    def __len__(self):
        pass

    def append(self, value):
        if self.head == None :
            self.head = Node(value)
            self.tail = self.head
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = Node(value)
            self.tail = temp.next

    def prepend(self, value):
        if self.head == None:
            self.head = Node
            self.tail = self.head
        else:
            temp = Node(value)

    def insert(self, value, index):
        pass

    def delete(self, value):
        pass

    def pop(self, index):
        pass

    def get(self, index):
        pass

    def print(self):
        pass


if __name__ == "__main__":
    pass