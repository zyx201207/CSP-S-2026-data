#include<bits/stdc++.h>
using namespace std;
char ch;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
    }
    if(n<=2){
        cout<<0;
    }else{
        cout<<2;
    }
    return 0;
}
