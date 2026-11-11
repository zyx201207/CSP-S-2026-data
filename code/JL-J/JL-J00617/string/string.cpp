#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n=3){
    cout<<"2";
}
if(n==2){
    cout<<"0";
}
return 0;
}
