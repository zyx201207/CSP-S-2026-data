#include <bits/stdc++.h>
using namespace std;
struct jjs{
long long a;
string c;
};
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int n,ans=0;
cin>>n;
jjs hang[n+3];
for(long long i=1;i<=n;i++){
    cin>>hang[i].a>>hang[i].c;
}
string s="";
for(long long i=1;i<=n;i++){
    for(long long j=1;j<=hang[i].a;j++){
        s+=hang[i].c;
    }
}
long long cd=s.size();
    for(long long i=0;i<cd/2;i++){
        if(s[i]!=s[cd-1-i]){
            ans++;
        }
    }
cout<<ans;
return 0;
}
