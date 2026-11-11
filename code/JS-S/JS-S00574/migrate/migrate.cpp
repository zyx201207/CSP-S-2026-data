
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e6+5;
ll cnt[N],ans[N];
ll get[N];
ll x[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        int n;ll d,Ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cnt[i]=1;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(x[n]-x[1]>d){cout<<0<<'\n';}
        int i=1;
       while(i<=n){
            int flag=-1;
            int pos=upper_bound(x+i+1,x+n+1,x[i])-x-1;
            if(pos==i+1){
                cnt[pos]+=cnt[i];
                i++;
                continue;
            }
            if(pos==i+2){
                int nxt1=upper_bound(x+pos+1,x+n+1,x[pos])-x-1;
                int nxt2=upper_bound(x+pos+1,x+n+1,x[pos-1])-x-1;
                for(int k=pos+1;k<=nxt2;k++){
                    ans[k]=1;
                    int kk=k;
                    while(kk+1<=n){
                        if(kk+2<=n&&x[kk+2]-x[kk]>d&&x[kk+1]-x[kk]<=d)ans[k]++;
                        else if(kk+1==n&&x[kk+1]-x[kk]<=d)ans[k]++;
                        else break;
                        kk++;
                    }
                }
                ll sum=0;
                for(int k=pos+1;k<=nxt2;k++)sum+=ans[k];
                Ans+=(cnt[i]-1)*(cnt[i])/2*sum;
            }
            else{
                int nxt1=upper_bound(x+pos+1,x+n+1,x[pos])-x-1;
                int nxt2=upper_bound(x+pos+1,x+n+1,x[pos-1])-x-1;
                int nxt3=upper_bound(x+pos+1,x+n+1,x[pos-2])-x-1;
                for(int k=max(pos+1,nxt3);k<=nxt2;k++){
                    ans[k]=1;
                    int kk=k;
                    while(kk+1<=n){
                        if(kk+2<=n&&x[kk+2]-x[kk]>d&&x[kk+1]-x[kk]<=d)ans[k]++;
                        else if(kk+1==n&&x[kk+1]-x[kk]<=d)ans[k]++;
                        else break;
                        kk++;
                    }
                }
                ll sum=0;
                for(int k=max(pos+1,nxt3);k<=nxt2;k++)sum+=ans[k];
                Ans+=(cnt[i]-1)*(cnt[i])/2*sum;
            }
            i++;
            cout<<Ans<<'\n';
        }

    }
}

