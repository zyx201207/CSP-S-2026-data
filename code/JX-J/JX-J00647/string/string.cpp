#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int n;
cin>>n;
vector<char> c;
int sum=0;
int ans=0;
for(int i=1;i<=n;i++){
    int a;
    char b;
    cin>>a>>b;
    sum +=b;
    for(int i=0;i<a;i++){
        c.push_back(b);
    }
}
for(int i=0,j=c.size()-1;i<j;i++,j--){
    if(c[i]!=c[j])
        ans++;
}
cout<<ans;
return 0;
}
