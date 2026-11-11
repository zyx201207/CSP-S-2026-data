#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
using ll = long long int;
struct node{
    int a;
    char c;
}a[MAXN];
ll len;
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        len+=a[i].a;
    }
    ll l=0,r=0;
    ll mid=len/2;
    if(n==1){
        cout<<0;
        return 0;
    }
    int i=1,j=n;
    while(l<mid&&r<mid){
        l+=a[i].a;
        r+=a[j].a;
        //cout<<l<<r;
        if(l==r){
            if(a[i].c!=a[j].c){
                ans+=a[i].a;
            }
            i++;
            j--;
            continue;
        }
        while(l<r){
            if(a[i].c!=a[j].c)ans+=a[i].a;
            //cout<<ans;
            i++;
            l+=a[i].a;
            if(l==r){
                if(a[i].c!=a[j].c)ans+=a[i].a;
            }
            if(l>r){
                ll rst=l-r;
                if(a[i].c!=a[j].c)ans+=a[i].a-rst;
                a[i].a=rst;
                l=r;
                i--;
            }
        }
        while(l>r){
            if(a[i].c!=a[j].c){
                ans+=a[j].a;
                //cout<<ans;
            }
            //cout<<ans;
            j--;
            r+=a[j].a;
            if(l==r){
                if(a[i].c!=a[j].c)ans+=a[j].a;
            }
            if(l<r){
                ll rst=r-l;
                if(a[i].c!=a[j].c)ans+=a[j].a-rst;
                a[j].a=rst;
                r=l;
                j++;
            }
        }
        //cout<<ans<<" "<<l<<r<<'\n';
        i++;j--;
    }
    cout<<ans;
    return 0;
}
