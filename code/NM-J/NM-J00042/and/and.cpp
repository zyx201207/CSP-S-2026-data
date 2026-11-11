#include<iostream>
using namespace std;
bool cmp1(int a,int b){
    return a<b;
}
int main(){
    int c,d,e[100001],f;
    cin>>c>>d;
    for(int i=1;i<=c;i++){
        cin>>e[i];
    }
    sort(e,e+c+1,cmp1);
    f=e[1];
    for(int i=1;i<=d;i++){
        e=e and e[i];
    }
    cout<<e;
return 0;
}
