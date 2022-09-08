package main

import (
	"fmt"
	"queues/queue"
)

func main() {
	q := queue.NewQueue(5)
	q.Enqueue(1)
	fmt.Println(q)
}
