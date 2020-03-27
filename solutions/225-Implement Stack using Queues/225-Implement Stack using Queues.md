#### 225-Implement Stack using Queues

#### Problem

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

**Example:**

> ```c++
> MyStack stack = new MyStack();
> 
>   stack.push(1);
>   stack.push(2);  
>   stack.top();   // returns 2
>   stack.pop();   // returns 2
>   stack.empty(); // returns false
>   ```

**Notes:**

​		You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
​		Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
​		You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

#### 问题

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空

注意:

​		你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
​		你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
​		你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。	

#### 思路

解题思路
如图，我们定义两个队列来实现栈，其中一个作为临时队列（queue2），一个作为存储栈中元素的队列（queue1）。

![image-20200327211617611](C:\Users\xy\AppData\Roaming\Typora\typora-user-images\image-20200327211617611.png)

因为队列是先进先出的数据结构，栈是后进先出的数据结构，元素的插入操作，只需要正常插入队列就行，插入后如图所示：

![image-20200327211659097](C:\Users\xy\AppData\Roaming\Typora\typora-user-images\image-20200327211659097.png)

当我们要移除栈顶元素时，应该移除最后插入的元素，此时，queue1中尾部的元素为栈顶元素。只需将queue1中的元素依次取出，存入queue2中，只保留最后一个元素，最后把queue1中剩余的元素删除，即实现了移除栈顶元素的操作，如图所示：

![image-20200327211736929](C:\Users\xy\AppData\Roaming\Typora\typora-user-images\image-20200327211736929.png)

在移除了栈顶元素之后，我们再将queue2中剩余的元素压入queue1中，如图所示：

![image-20200327211747924](C:\Users\xy\AppData\Roaming\Typora\typora-user-images\image-20200327211747924.png)

获取栈顶元素时，因为最后入栈的元素为栈顶元素，所以可以定义一个变量保存每次最后入栈的元素，这样便可以直接获取栈顶元素。但是，在移除栈顶元素之后，栈顶元素变为原来栈顶元素下面的元素，所以，此时要将变量的值改为原来栈顶元素下面的元素，即queue1的队尾元素。
因为每次都是将所有的元素放入queue1中，所以只要queue1为空，栈就为空。

**代码：**

```c++
class MyStack {
private:
    queue<int> queue1, queue2;
    int topValue;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        topValue = x;
        queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int stackpop;
        while(queue1.size() > 1){
            int temp = queue1.front();
            queue2.push(temp);
            queue1.pop();
        }
        stackpop = queue1.front();
        queue1.pop();
        while(queue2.size() > 0){
            int temp = queue2.front();
            queue1.push(temp);
            queue2.pop();
        }
        topValue = queue1.back();
        return stackpop;
    }
    
    /** Get the top element. */
    int top() {
        return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(queue1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

