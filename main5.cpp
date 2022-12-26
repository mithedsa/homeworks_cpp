#include <iostream>
#include <cassert>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);

    char *content_{nullptr};
    int size_{0};

    void resize(int newsize){
        if (size_ == newsize)
            return;
        char *temp = new char[newsize]{};
        if (newsize > size_)
            std::copy(content_, content_ + size_, temp);
        else
            std::copy(content_, content_ + newsize, temp);
        delete[] content_;
        content_ = temp;
        size_ = newsize;
    }

public:
    String() = default;
    String(char ch, int size){
        
        resize(size);
        std::fill(content_, content_ + size_, ch);
    }
    explicit String(int size){
 
        resize(size);
        for (int i = 0; i < size; i++)
            content_[i] = char(33 + int(93*double(rand())/32768));
    }
    String(const char *liter, int size){
        resize(size);
        std::copy(liter, liter + size, content_);
    
    }
    String(const String &right){
        resize(right.size_);
        std::copy(right.content_, right.content_ + right.size_, content_);

    }
    ~String() {
        delete[] content_;
        content_ = nullptr;
        size_ = 0;
    }

    String& operator=(const String &right){
    
        new (this) String(right);
        return *this;
    }

    char& operator[](int index) {
        assert(index < size_);
        return content_[index];
    }
    String operator+(const String &right){
        return this->concatenate(right);
    }
    void operator+=(const String &right){
        int oldsize = size_;
        this->resize(this->len()+right.len());
        std::copy(right.content_, right.content_ + right.size_, this->content_ + oldsize);

    }
    bool operator==(const String &right){
        if (this->len() != right.len())
            return false;
        for (int i = 0; i < this->size_; i++)
            if (this->content_[i] != right.content_[i])
                return false;
        return true;
    }
    bool operator!=(const String &right){
        if (this->len() == right.len())
            return false;
        for (int i = 0; i < this->size_; i++)
            if (this->content_[i] == right.content_[i])
                return false;
        return true;
    }
    bool operator>(const String &right) const{
        return (this->len() > right.len());
    }
    bool operator<(const String &right) const{
        return (this->len() < right.len());
    };
    bool operator<=(const String &right) const{
        return (this->len() <= right.len());
    };
    bool operator>=(const String &right) const{
        return (this->len() >= right.len());
    };

    int len() const {return size_;}

    String upper(){
        String res = String(this->content_,this->size_);
        for (int i = 0; i < size_; i++){
            if (this->content_[i] >= 'a' and this->content_[i] <= 'z')
                res[i] = char(int(this->content_[i]) - ('a' - 'A'));
        }
        return res;
    }
    String lower(){
        String res = String(this->content_,this->size_);
        for (int i = 0; i < size_; i++)
            if (this->content_[i] >= 'A' and this->content_[i] <= 'Z')
                res[i] = char(int(this->content_[i]) + ('a' - 'A'));
        return res;
    }

    String concatenate(const String &right){
        String res = String(' ', this->len() + right.len());
        for (int i = 0; i < this->len(); i++)
            res[i] = this->content_[i];
        for (int i = this->len(); i < res.len(); i++)
            res[i] = right.content_[i - this->len()];
        return res;
    }
};


std::ostream& operator<<(std::ostream& os, const String& obj)
{
    for (int i = 0; i < obj.size_; i++)
        os << obj.content_[i];
    return os;
}


int main(){
    String teststr("COck", 4);
    String test2("check", 5);
    test2 += test2;
    std::cout << teststr.concatenate(test2.lower()) << '\n';
    std::cout << test2 + teststr << '\n' << (test2 != test2) << ' ' << (teststr < test2) << '\n';
    test2 = String("test", 4);
    String test3 = test2;
    teststr = String(10);
    String test4;
    test4 = teststr;
    std::cout << test3.upper() << ' ' << test4.lower();
    return 0;
}
