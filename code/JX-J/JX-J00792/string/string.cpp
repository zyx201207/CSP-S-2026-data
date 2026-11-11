#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
char a,b[1000000];
int n,num,sum=1,s=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>num>>a;
    for(int j=1;j<=num;j++){
        b[sum]=a;
        sum++;
    }
}
for(int i=1;i<=sum/2;i++){
    if(b[i]!=b[sum-i])
    s++;}
cout<<s;
return 0;
}
