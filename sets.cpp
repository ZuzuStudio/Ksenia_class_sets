#include "sets.h"

Set::Set():
    elements_set(0)
{
    elements_set = NULL;
};

Set::~Set(){
    delete[]elements_set;
    elements_set=0;
}

Set::Set(const Set &equally){

    n = equally.n;

    elements_set = NULL;

    elements_set = new int[n];

    for (int i=0; i<n; ++i)
        elements_set[i] = equally.elements_set[i];
}

//////////////////////////////////

istream& operator>>(istream &in, Set &a){
    in >> a.n;

    a.elements_set = new int [a.n];
    for (int i=0; i<a.n; ++i){
        in>>a.elements_set[i];
    }
    return in;
}

ostream& operator<<(ostream &out ,const Set &a){
    for (int i=0; i<a.n; ++i){
        out << a.elements_set[i] << ' ';
    }
    out << endl;
    return out;
}

//////////////////////////////////

Set Set::operator+(const Set &unio) const{
    int r=0,N=n;
    int *c = new int[n+unio.n];

    for (int i=0; i<n+unio.n; ++i){
        c[i] = elements_set[i];
    }

    for (int l=0; l<unio.n; ++l){
        int k=0;
        for (int j=0; j<n; ++j){
            if (unio.elements_set[l] == c[j])
                ++k;
        }
        if (!k){
            c[n+r] = unio.elements_set[l];
            ++r;++N;
        }
    }

    Set x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}

Set Set::operator=(const Set &equally){

    n = equally.n;

    if (elements_set)
    delete []elements_set;

    elements_set = new int[n];

    for (int i=0; i<n; ++i)
        elements_set[i] = equally.elements_set[i];

    return *this;
}

Set Set::operator*(const Set &intersect) const{
    int N=0,r=0;
    int *c = new int[n+intersect.n];

    for (int i=0; i<intersect.n; ++i){
        int k=0;
        for (int j=0; j<n; ++j){
            if (elements_set[i] == intersect.elements_set[j])
                ++k;
        }
        if (k){
            c[r] = elements_set[i];
            ++N;++r;
        }
    }

    Set x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}

Set Set::operator-(const Set &differ) const{

    int r=0,N=0;
    int *c = new int[n+differ.n];

    for (int i=0; i<n; ++i){
        int k=0;
        for (int j=0; j<differ.n; ++j){
            if (elements_set[i] == differ.elements_set[j])
                ++k;
        }
        if (!k){
            c[r] = elements_set[i];
            ++r;++N;
        }
    }

    Set x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}

