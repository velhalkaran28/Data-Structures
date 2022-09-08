package main

import "fmt"

type Stack struct {
	stack []int
	size  int
}

func (s *Stack) Push(value int) {
	if len(s.stack) == s.size {
		fmt.Println("Stack already full")
		return
	}
	s.stack = append(s.stack, value)
}

func (s *Stack) Pop() int {
	if len(s.stack) == 0 {
		fmt.Println("Stack is empty!")
		return -1
	}
	lastItem := s.stack[len(s.stack)-1]
	s.stack = s.stack[:len(s.stack)-1]
	return lastItem
}

func (s *Stack) Top() int {
	if len(s.stack) == 0 {
		fmt.Println("Stack is empty!")
		return -1
	}
	return s.stack[len(s.stack)-1]
}

func main() {
	stk := Stack{size: 5}
	stk.Push(10)
	stk.Push(20)
	fmt.Println(stk.Pop(), " popped")
	fmt.Println(stk.Pop(), " popped")
	fmt.Println(stk.Top())
}
