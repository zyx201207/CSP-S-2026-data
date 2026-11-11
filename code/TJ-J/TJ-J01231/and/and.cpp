#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,n,m,q,w,e;
    cin>>n>>m>>q>>w>>e;
    a=n & m&q&w&e;
    if (a==0){
        cout <<q;
    }else {
    cout<<m;
    }





}
