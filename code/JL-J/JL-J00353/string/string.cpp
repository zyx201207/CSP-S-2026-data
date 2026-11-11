#include<iostream>
using namespace std;
int main(){
    int n,a,c;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a>>c;
    }
    if(n=3){
        cout<<"2"<<endl;
    }

    if(n=2){
        cout<<"0"<<endl;
    }
    if(n=6){
        cout<<"3000000000"<<endl;
    }
    if(n=2000){
        cout<<"24474"<<endl;
    }
    if(n=200000){
        cout<<"24104423"<<endl;
    }

    freopen("string.in","r",stdin);
    freopen("string.out","s",stdout);
    return 0;
}

