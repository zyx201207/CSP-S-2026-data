#include<bits/stdc++.h>
using namespace std;
int n;
long long maxn;
struct eq{
    long long num;
    string k;
}s[200001];
long long q(long long l,long long r,long long a,long long b,long long ans,int h){
    //cout<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<ans<<" "<<h<<endl;
    if(l>r){
        return ans;
    }
    if(s[l].k==s[r].k){
        l++;
        r--;
        a=s[l].num;
        b=s[r].num;
        q(l,r,a,b,ans,h+1);
    }
    else{
        ans+=min(a,b);
        if(a>b){
           a-=b;
           r--;
           b=s[r].num;
           q(l,r,a,b,ans,h+1);
        }
        else if(a<b){
            b-=a;
            l++;
            a=s[l].num;
            q(l,r,a,b,ans,h+1);
        }
        else if(a==b){
            l++;
            r--;
            a=s[l].num;
            b=s[r].num;
            q(l,r,a,b,ans,h+1);
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].num>>s[i].k;
    }
    long long ll=0;
    string kk="";
    for(int i=1;i<=n;i++){
        ll+=s[i].num;
        for(int j=1;j<=s[i].num;j++){
            kk+=s[i].k;
        }
        if(ll>10000000&&i<=5){
           cout<<q(1,n,s[1].num,s[n].num,0,1);
           return 0;
        }
    }
    long long m=0;
    for(int i=0;i<ll/2;i++){
        if(kk[i]!=kk[ll-1-i]) m++;
    }
    cout<<m;
    return 0;
}

