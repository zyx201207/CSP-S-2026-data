#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string s="E";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    int a;
    char c;
    cin>>a>>c;
    for(int j=0;j<a;j++){
        s+=c;
    }
}
int l=0;
if((s.size()-1)%2==1)
    l=(s.size()-1)/2+1;
else
    l=(s.size()-1)/2;
for(int i=1;i<=l;i++){
    if(s[i]!=s[s.size()-i]){
        ans++;
    }
}
cout<<ans<<" ";
    return 0;
}
