#include<bits/stdc++.h>
using namespace std;
long long n,c[222222],m,ans;
string a[222222];
string se(long long x){
    string ss;
    while(x!=0){
        ss+=x%2+'0';
        x/=2;
    }
    return ss;
}
bool cmp(long long h,long long j){
    return h>j;
}
long long po(long long x,long long y){
    if(y==0) return 1;
    for(int i=2;i<=y;i++){
        x*=x;
    }
    return x;
}
long long es(string o){
    long long aa=0;
    for(int i=0;i<o.size();i++){
        aa+=(o[i]-'0')*po(2,i);
    }
    return aa;
}
string an(string q,string p){
    for(int i=0;i<max(q.size(),p.size());i++){
        if(q[i]&&p[i]) q[i]='1';
        else q[i]='0';
    }
    return q;
}
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1,cmp);
    if(m==1){
        cout<<c[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=se(c[i]);
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=es(an(se(ans),a[i]));
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,es(an(a[i],a[j])));
            }
        }
        cout<<ans;
    }
    return 0;
}
