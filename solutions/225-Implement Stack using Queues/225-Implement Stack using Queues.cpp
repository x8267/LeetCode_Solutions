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