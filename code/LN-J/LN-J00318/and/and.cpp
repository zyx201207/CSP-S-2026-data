#include<bits/stdc++.h>
using namespace std;
struct b{
    long long x;
    string y;
}a[200005];
bool cmp(b g,b h){
    return g.y>h.y;
}
long long dp(){
    string ans=" ";
    string t=" ";
    while(a>0){
        if(a[i]%2==1){
            t+="1";
        }else{
            t+="0";
        }
        a[i]/=2;
    }
    int l=t.length();
    for(long long i=0;i<t.length();i++){
        ans+=t[l-i-1];
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n;
    long long m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=dp(a[i].x);
    }
    sort(a+1,a+1+n,cmp);
    long long ans=a[1].x;
    for(long long i=2;i<=m;i++){
        ans&=a[i].x;
    }
    return 0;
}
