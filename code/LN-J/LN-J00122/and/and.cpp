#ifndef AND_CPP_INCLUDED
#define AND_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    int n,m,a[2001]={};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n);
    cout<<a[0];
    return 0;
}

#endif // AND_CPP_INCLUDED
