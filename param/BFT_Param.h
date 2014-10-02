#pragma once

#include <iostream>
using namespace std;

class DataWrap{
public:
    virtual void GetData(){}	
    virtual ~DataWrap(){}	
};

class CBFT_Param
{
public:

    template< typename T >
    class DataWrapImpl : public DataWrap {
	public:
        T _Data;
        DataWrapImpl( T Data ) : _Data( Data ){
            cout<< "_Data: " << _Data <<endl;
        }
        DataWrapImpl( DataWrapImpl const & a ) : _Data( a._Data ){
            cout<< "_Data: " << _Data <<endl;      
        }
        DataWrapImpl& operator= ( DataWrapImpl const & a ){
            _Data = a._Data;
            cout<< "_Data: " << _Data <<endl;
            return *this;
        }
        ~DataWrapImpl(){
            _Data = 0;
        }
    };

    DataWrap * _d;

    template< typename T >
    CBFT_Param( T Data ) : _d( new DataWrapImpl<T>( Data ) ){}

    ~CBFT_Param(){
        if( _d != 0 ){
            delete _d;
            _d = 0;
        } 
    }

    template< typename T >
    bool getParam( T & Out ){
        DataWrapImpl<T> * _temp;
        _temp = dynamic_cast<DataWrapImpl<T> * > ( _d );
        if(_temp){
            Out = _temp->_Data;
            return true;
        }else{
            return false;
        }
    }

private:
    CBFT_Param( CBFT_Param const & a ); 
};
