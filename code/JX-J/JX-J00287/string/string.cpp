#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s[1000000000000001]={0};
    int n,x=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        x=x+a;
        for(int j=1;i<=a;j++){
            s[j]=b;
        }
    }
    if(x%2==1){
        for(int i=1;i<=(x+1)/2;i++){
            if(s[i]!=s[x]){
                c++;
            }
            x=x-1;
        }
    }else{
        for(int i=1;i<=x/2;i++){
            if(s[i]!=s[x]){
                c++;
            }
            x=x-1;
        }
    }
    cout<<c<<endl;
    return 0;
}
