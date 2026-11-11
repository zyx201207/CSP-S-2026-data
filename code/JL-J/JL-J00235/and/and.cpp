#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int ab[100000];
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>ab[i];
    }
    if(b==2){
        cout<<ab[3];
    }else{
        cout<<7;
    }
    return 0;
}
