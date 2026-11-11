#include<bits/stdc++.h>
#define ll long long
#define atn 222222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(ll i=a;i<=b;++i)
using namespace std;
ll n,a[atn];
char c[atn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
        cin>>n;
    ll sum=0;
    f(i,1,n)cin>>a[i]>>c[i],sum+=a[i];
    ll pos1=1,pos2=n,ans=0;
    while(pos1<pos2){
        if(a[pos1]<a[pos2]){
            if(c[pos1]!=c[pos2])ans+=a[pos1];
            a[pos2]-=a[pos1],pos1++;
        }
        else if(a[pos1]==a[pos2]){
            if(c[pos1]!=c[pos2])ans+=a[pos1];
            pos1++,pos2--;
        }
        else{
            if(c[pos1]!=c[pos2])ans+=a[pos2];
            a[pos1]-=a[pos2],pos2--;
        }
    }
    cout<<ans;


    return 0;
}
