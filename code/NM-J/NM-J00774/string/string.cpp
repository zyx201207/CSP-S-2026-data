#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int a,c=0,n,j,ans,k;
char b;
string m;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a>>b;
    for(int j=0;j<a;j++){
        m[j+c]=b;
    }
    c=c+a;

}
for(int i=0;i<c;i++){
    j=c-i-k;
    if(m[j]!=m[i]){
        m[j]==m[i];
        k++; 
        ans++;
    }
}
cout<<ans;
return 0;
}
