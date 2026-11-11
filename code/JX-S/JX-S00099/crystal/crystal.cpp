#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[50005],b[50005],t[50005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    //cout<<"1";
    sort(a+1,a+n+1);
    int mid,l=a[0],r=a[n],pre=-1;
    while(l<r){
        mid=(l+r)/2;
        int start=n;
        int num=m;
        for(int i=1;i<=n;++i){
            b[i]=mid-a[i];
        }
        for(int i=1;i<=n;++i){
            if(b[i]<0){
                start=i;
                break;
            }
        }
        for(int i=start-1;i>=1;--i){
            if(num>=b[i])num-=b[i];
        }
        if(num>0||num<pre)r=mid-1;
        else l=mid;
        pre=num;
    }
    int cnt=0,is1=0,now=0x3f3f3f3f;
    for(int i=1;i<=n;++i){
        if(a[i]<=mid)++cnt;
        else{
            if(a[i]==now){
                ++cnt;
                if(is1)++cnt;
                is1=0;
            }
            else {
                now=a[i];
                is1=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
