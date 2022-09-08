package queue

import "fmt"

type Queue struct {
	queue []int
	size  int
	front int
	rear  int
}

func NewQueue(size int) Queue {
	return Queue{make([]int, size), size, -1, -1}
}

func (q *Queue) Enqueue(value int) bool {
	q.rear++
	if q.rear == q.size {
		fmt.Println("Queue is full!")
		return false
	}
	q.queue[q.rear] = value
	return true
}

func (q *Queue) Dequeue() int {
	if q.front == q.rear {
		fmt.Println("Queue is empty!")
		return -1
	}
	q.front++
	removedElement := q.queue[0]
	q.queue = q.queue[1:]
	return removedElement
}
