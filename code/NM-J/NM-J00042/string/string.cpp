#include<iostream>
using namespace std;
int main(){
    int h,l[1000001],e,r;
    char c[1000001];
    cin>>h;
    for(int i=1;i<=h;i++){
        cin>>l[i];
        cin>>c[i];
    }
    e=0;
    for(int i=1;i<=h;i++){
        if(c[i]!=c[1]){
            continue;
        }
        if(c[i]==c[1]){
            e+=l[i];
        }
    }
    for(int i=h-1;i>=h;i--){
        if(c[1]==c[i]){
            r-=l[i];
        }

    }
    e+=r;
    cout<<e;
    return 0;
}

