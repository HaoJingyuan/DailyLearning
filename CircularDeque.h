//实现双端队列
//当前数量num，注意增加删除时对num的修改。最后一个元素索引始终为num-1，那么要求增加元素时先num++，后使用data[num-1],删除时先使用data[num-1],后num--
//判断能够插入删除的依据都是当前元素个数
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
        num = 0;
        data = new int[size];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(num >= size)
        {
            return false;
        }
        else
        {
            num++;
            for(int i = num - 2;i >=0;i--)
            {
                data[i + 1] = data[i];
            }
            data[0] = value;
            return true;
        }

    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(num >= size)
        {
            return false;
        }
        else
        {
            num++;
            data[num-1] = value;
            return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(num > 0)
        {
            for(int i = 0;i < num - 1;i++)
            {
                data[i] = data[i + 1];
            }   
            num--;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(num > 0)
        {
            data[num - 1] = 0;
            num--;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(num > 0)
        {
            return data[0];
        }
        else{return -1;}
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(num > 0)
        {
            return data[num -1];
        }
        else{return -1;}
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(num == 0)
        {
            return true;
        }
        else{return false;}
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(num == size)
        {
            return true;
        }
        else{return false;}
    }
private:
    int *data;
    int size;
    int num;
};