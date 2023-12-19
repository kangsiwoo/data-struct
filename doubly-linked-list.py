class doublyLinkedList:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def createNode(self, data):
        self.data = data

    def insertFirst(self, data):
        newNode = doublyLinkedList(data)
        self.prev = newNode
        newNode.next = self

        return newNode

    def insertLast(self, data):
        newNode = doublyLinkedList(data)
        temp = self

        while temp.next is not None:
            temp = temp.next

        temp.next = newNode
        newNode.prev = temp

    def deleteFirst(self):
        temp = self.next
        temp.prev = None

        return temp

    def deleteLast(self):
        temp = self

        while temp.next is not None:
            temp = temp.next

        temp = temp.prev
        temp.next.prev = None
        temp.next = None



head = doublyLinkedList(30)

head = head.insertFirst(20)
head = head.insertFirst(10)

head.insertLast(40)
head.insertLast(50)

head = head.deleteFirst()
head.deleteLast()

