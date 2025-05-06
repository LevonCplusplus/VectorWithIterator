template <typename T> 
    Vector<T>::Vector():m_size(0),m_capacity(5){
    m_data=new T [m_capacity];
    };
    template <typename T> 
    Vector<T>::~Vector(){
    delete[] m_data;
    }
    template <typename T> 
    Vector<T>::Vector(const Vector<T> & vec)
    {
        m_size=vec.m_size;
        m_capacity=vec.m_capacity;
        m_data=new int[vec.m_capacity];
        for(int i=0;i<vec.m_size;++i)
        {
            m_data[i]=vec.m_data[i];
        }
    }
    template <typename T> 
    T& Vector<T>::at (size_t index){
        if(index >= m_size )
        exit(-1);
    return m_data[index];   
    }
    template <typename T> 
    void Vector <T>::reallocate(size_t capacity)
    {
        T *p=new T[capacity];
        if(!p)
        {
            exit(-1);
        }
        for(int i=0;i<m_size;++i)
        {
            p[i]=m_data[i];
        }
        delete[]m_data;
        m_data=p;
        p=nullptr;
        m_capacity=capacity;
    }
    template <typename T> 
    template <typename P>
    void Vector<T>::push_back(P && val){
    if(m_size == m_capacity)
    {
        reallocate(2 * m_capacity);
    }
    m_data[m_size] = val;
    ++ m_size;
    }
    template <typename T> 
    void Vector<T>::pop_back(){
    if(m_size > 0){
        --m_size;
    }
    }
    template <typename T> 
    size_t Vector<T>:: get_Size(){
    return m_size;
    }
    template <typename T> 
    size_t Vector<T>:: get_Cap(){
        return m_capacity;
    }
    template <typename T> 
    void Vector<T>:: resize(size_t size){
        m_size=size;
    }
    template <typename T> 
    void Vector<T>:: reserve(size_t capacity){
    reallocate(capacity);
    }
    template <typename T> 
    T Vector<T>:: front()const{
    return m_data[0];
    }
    template <typename T> 
    T Vector<T>:: back()const{
    return m_data[m_size-1];
    }
    template <typename T> 
    bool Vector<T>:: is_empty()const{
    if(!m_size){
        return true;
    }
    return false;
    }
    template <typename T> 
    void Vector<T>:: shrink_to_fit(){
        reallocate(m_size);
    } 
    template <typename T> 
    void Vector<T>:: insert(size_t index,T & value){
        if(m_size == m_capacity)
        {
            reallocate(m_capacity*2);
        }
        for(int i=m_size-1;i>=index;--i)
        {
            m_data[i+1]=m_data[i];
        }
        m_data[index]=value;
        m_size++;
    }
    template <typename T> 
    void Vector<T>:: erase(size_t index){
    for(int i=index;i<m_size-1;++i)
    {
        m_data[i]=m_data[i+1];
    }   
    } 
    template <typename T> 
    T& Vector<T>:: operator[](size_t n){
        return this->at(n);
    }
    template <typename T> 
    void Vector<T>:: clear(){
        m_size=0;
    }
