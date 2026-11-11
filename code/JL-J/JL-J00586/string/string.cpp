#include<bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
char c1;
char c2;
int a1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        if(i==0){
            a1=a;
            c1=c;
        }
        if(i+1==n){
            c2=c;
        }
    }
    if(c1!=c2){
        cout<<n-a;
    }
    else cout<<0;
    return 0;
}
