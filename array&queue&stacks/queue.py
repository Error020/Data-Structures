class Queue:

    def __init__(self, c):

        self.queue = []
        self.front = self.rear = 0
        self.capacity = c

    def queueEnqueue(self, data):

        if(self.capacity == self.rear):
            print("\nWarteschlange ist voll!")

        else:
            self.queue.append(data)
            self.rear += 1

    def queueDequeue(self):

        if(self.front == self.rear):
            print("\nWarteschlange ist leer!")

        else:
            x = self.queue.pop(0)
            self.rear -= 1

    def queueDisplay(self):

        if(self.front == self.rear):
            print("\nWarteschlange ist leer!")

        for i in self.queue: 
            print(i, "<--", end = '') 

    def queueFront(self):

        if(self.front == self.rear):
            print("\nWarteschlange ist leer!")

        print("\nFront Element ist: ",
            self.queue[self.front])



if __name__=='__main__':

    q = Queue(4)

    q.queueDisplay()

    q.queueEnqueue(1)
    q.queueEnqueue(2)
    q.queueEnqueue(3)
    q.queueEnqueue(14)

    q.queueDisplay

    q.queueEnqueue(5)

    q.queueDequeue()
    q.queueDequeue()
    q.queueDequeue()

    print("\n")
    q.queueDisplay()

    q.queueFront()