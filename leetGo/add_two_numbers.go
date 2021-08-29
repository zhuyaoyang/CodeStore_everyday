package main

import "fmt"

// 1修改：数在链表中正序存储 如123就是，1->2->3

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l1 := &ListNode{Val: 4, Next: nil}
	l2 := &ListNode{Val: 3, Next: l1}
	l3 := &ListNode{Val: 2, Next: l2}
	l4 := &ListNode{Val: 7, Next: nil}
	l5 := &ListNode{Val: 6, Next: l4}
	l6 := &ListNode{Val: 5, Next: l5}
	res := addTwoNumbers(l6, l3)
	for res != nil {
		fmt.Print(res.Val)
		res = res.Next
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	res := new(ListNode) //new函数会分配内存，返回的值是一个指向该类型零值的地址
	resHead := res
	cur1 := reverseList(l1)
	cur2 := reverseList(l2)
	carry := 0

	for cur1 != nil && cur2 != nil {
		res.Val = cur1.Val + cur2.Val + carry
		carry = 0
		if res.Val > 9 {
			carry = 1
			res.Val -= 10
		}
		cur1 = cur1.Next
		cur2 = cur2.Next
		if cur1 != nil && cur2 != nil {
			res.Next = new(ListNode)
			res = res.Next
		}
	}
	cur := new(ListNode)
	if cur2 != nil {
		cur = cur2
	} else {
		cur = cur1
	}
	for cur != nil {
		res.Next = new(ListNode)
		res = res.Next
		res.Val = cur.Val + carry
		carry = 0
		if res.Val > 9 {
			carry = 1
			res.Val -= 10
		}
		cur = cur.Next
	}
	if carry == 1 {
		res.Next = new(ListNode)
		res = res.Next
		res.Val = 1
	}
	return reverseList(resHead)
}

func reverseList(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}
	var (
		past *ListNode
		cur  *ListNode
		next *ListNode
	)
	cur = l
	past = nil
	for cur != nil {
		next = cur.Next
		cur.Next = past
		past = cur
		cur = next
	}
	return past
}
