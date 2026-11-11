#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
    int len;
    char c;
    int s,e;
}a[N];
int n,cnt=0,ans=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int len;char c;
        cin>>len;cin>>c;
        a[i].len=len;a[i].c=c;
        a[i].s=cnt+1;a[i].e=cnt+a[i].len;
        cnt+=a[i].len;
    }
    //int l=1,r=n;
    int lpos=0,rpos=cnt+1;
    int i=1,j=n;
    for(;i<=n;i++){
        if(lpos+a[i].len>rpos-a[i].len) break;
        lpos+=a[i].len;
        int need=rpos-a[i].len;
        while(a[j].s>need){
            if(a[j].c!=a[i].c){
                //cout<<rpos-a[j].s<<" ";
                ans+=(rpos-a[j].s);
            }
            rpos=a[j].s;
            j--;
        }
        if(a[j].c!=a[i].c) ans+=(rpos-need);
        rpos=need;
        //cout<<ans<<endl;
    }
    int mid=(lpos+rpos)>>1;
    while(a[j].s>mid){
        if(a[j].c!=a[i].c){
            ans+=rpos-a[j].s;
        }
        rpos=a[j].s;
        j--;
    }
    cout<<ans<<endl;
}
