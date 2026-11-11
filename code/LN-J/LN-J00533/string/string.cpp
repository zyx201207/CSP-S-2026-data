#include<iostream>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string,out","w",stdout);
    int i,n,x,xx=0,j;
    char a;
    cin>>n>>x;
    cin>>a;
    char s=a;
    i=1;
    while(i<n){
        s=s+a;
        i++;
    }
    xx=xx+x;
    i=1;
    while(i<n){
       cin>>x;
       cin>>a;
       j=0;
       while(j<x){
            s=s+a;
            j++;
       }
       xx=x+xx;
       i++;
    }
    i=0;
    j=0;
    if(xx%2==0){
        xx=xx/2;
    }else{
        xx=xx/2+1;
    }
    while(i<xx){
        if(char(i)!=char(xx-i)){
            j++;
        }
        i++;
    }
    cout<<j;
    return 0;
}
