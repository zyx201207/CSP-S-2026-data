#include<bits/stdc++.h>
using namespace std;
string a1,b1;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a,sum=1,man=1;
char b;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a>>b;
    for(int j=1;j<=a;j++){
        a1[sum]+=b;
        sum++;
    }
}
for(int i=sum-1;i>=0;i--){
    b1[man]=a1[i];
    man++;
}
man=0;
for(int i=1;i<=sum;i++){
    if(a1[i]!=b1[i])
        man++;
}
if(man<=1)
cout<<man;
else
cout<<man/2;
}
