#include<bits/stdc++.h>
using namespace std;
string f(int a,int b){
    string s,v;
    string h;
    while(a){
        s+=(a%2)+'0';
        a/=2;
    }
    while(b){
        v+=(b%2)+'0';
        b/=2;
    }
    for(int i=1;i<=max(s.size(),v.size());i++){
        if(v[i]=='1'&&s[i]=='1'){
            h[i]='1';
        }
        else{
            h[i]='0';
        }
    }
    return h;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m;
cin>>n>>m;
int a[100010];
if(n==1){
    cout<<n;
    return 0;
}
for(int i=1;i<=n;i++){
    cin>>a[i];
}
int cnt=0,sum=0;
int r=1;
for(int i=1;i<=n;i++){
    string s=f(a[i],a[i+1]);
    for(int j=1;j<=s.size();j++){
        int x=(int)(s[i]-'0');
        cnt+=x*r;
        r*=2;
    }
    if(cnt>sum){
        sum=cnt;
    }
}
cout<<sum;
return 0;
}
