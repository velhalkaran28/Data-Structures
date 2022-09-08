package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
	len  int
}

func (l *LinkedList) Add(value int) {
	newNode := new(Node)
	newNode.value = value

	if l.head == nil {
		l.head = newNode
	} else {
		ptr := l.head
		for ptr.next != nil {
			ptr = ptr.next
		}
		ptr.next = newNode
	}
}

func (l *LinkedList) InsertAtFirst(value int) {
	newNode := new(Node)
	newNode.value = value

	if l.head == nil {
		l.head = newNode
		return
	}
	newNode.next = l.head
	l.head = newNode
}

func (l *LinkedList) InsertAtPos(value, pos int) {
	newNode := new(Node)
	newNode.value = value
	ptr := l.head
	for i := 0; i < pos-1; i++ {
		ptr = ptr.next

	}
	newNode.next = ptr.next
	ptr.next = newNode
}

func (l *LinkedList) Remove(value int) {

}

func (l *LinkedList) Search(value int) {
	for ptr := l.head; ptr != nil; ptr = ptr.next {
		if ptr.value == value {
			fmt.Println("Data found = ", ptr.value)
			return
		}
	}
	fmt.Println("Not found!")
}

func (l *LinkedList) Count() {
	count := 0
	for ptr := l.head; ptr != nil; ptr = ptr.next {
		count++
	}
	fmt.Println(count)
}

func (l *LinkedList) Display() {
	for ptr := l.head; ptr != nil; ptr = ptr.next {
		fmt.Printf("%d \t", ptr.value)
	}
}

func (l *LinkedList) DisplayRecursion(ptr *Node) {
	if ptr != nil {
		fmt.Printf("%d \t", ptr.value)
		l.DisplayRecursion(ptr.next)
	}
}

func (l *LinkedList) DeleteFirstNode() {
	if l.head.next != nil {
		ptr := l.head
		l.head = ptr.next
		ptr = nil
	} else {
		l.head = nil
	}
}

func (l *LinkedList) ReverseLinkedList() {
	p := l.head
	var q *Node
	var r *Node
	for p != nil {
		r = q
		q = p
		p = p.next
		q.next = r
	}
	l.head = q
}

func (l *LinkedList) ReverseRecursion(q *Node, p *Node) {
	if p != nil {
		l.ReverseRecursion(p, p.next)
		p.next = q
	} else {
		l.head = q
	}
}

func main() {
	l := LinkedList{}
	l.Add(1)
	l.Add(2)
	l.Display()

	// l.Search(3)
	// l.Count()
	// l.InsertAtFirst(3)
	// l.InsertAtPos(11, 2)
	// l.ReverseLinkedList()
	l.ReverseRecursion(nil, l.head)
	l.DisplayRecursion(l.head)
}
