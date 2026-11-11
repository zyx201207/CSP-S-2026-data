#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,l,r,restl,restr,posl,posr,ans,a[220000],pre[220000];
char c[220000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        pre[i]=pre[i-1]+a[i];
    }
    len=pre[n];
    int mid=len>>1;
    r=len;
    restl=a[1];
    restr=a[n];
    posl=1;
    posr=n;
    while(l<=mid&&r>=n-mid+1){
        bool flag=0;
        if(posl>=posr){
            break;
        }
        if(c[posl]!=c[posr]){
            flag=1;
        }
        if(restl>restr){
            r-=restr;
            l+=restr;
            restl-=restr;
            if(flag){
                ans+=restr;
            }
            restr=a[--posr];
        }
        else if(restl<restr){
            r-=restl;
            l+=restl;
            restr-=restl;
            if(flag){
                ans+=restl;
            }
            restl=a[++posl];
        }
        else{
            r-=restl;
            l+=restl;
            if(flag){
                ans+=restl;
            }
            restl=a[++posl];
            restr=a[--posr];
        }
    }
    cout<<ans<<endl;
    return 0;
}
