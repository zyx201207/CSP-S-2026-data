#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans=1,p;
string b[100005],c[100005];
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
}
for(int i=n;i>=1;i--){
    c[ans]=b[i];
    ans+=1;
}
for(int i=1;i<=n;i++){
    if(b[i]==c[i]){
        p++;
    }
}
cout<<(n-p)/2;
return 0;
}
