/*
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
string s="";
ll n,a,ans;
char c;
int main()
{
    freopen("string.in","r",stdout);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        scanf("%lld %c",&a,&c);
        while(a--)s+=c;
    }
    ll len=s.size(),mid=(len+1)/2;
    for(ll i=0;i<mid;++i)
        if(s[i]!=s[len-i-1])++ans;
    cout<<ans;
    return 0;
}
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n;
ll ans;
struct node{ll x;char c;}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld %c",&a[i].x,&a[i].c);
    int l=1,r=n;
    while(l<r){
        ll x=a[l].x,y=a[r].x,num=min(x,y);
        if(a[l].c!=a[r].c){
            ans+=num;
        }
        a[l].x-=num,a[r].x-=num;
        if(!a[l].x)++l;
        if(!a[r].x)--r;
    }
    printf("%lld",ans);
    return 0;
}
