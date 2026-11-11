#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+60;
int c,T,n;
ll d;
ll a[N];
int r[N];
int L,R,mid,res;
ll ans;
ll f1[N];
ll f2[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n;
        cin>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            L=i;
            R=n;
            res=i;
            while(L<=R){
                mid=(L+R)>>1;
                if(a[mid]-a[i]<=d){
                    L=mid+1;
                    res=mid;
                }else R=mid-1;
            }
            r[i]=res;
        }
        ans=0ll;
        f1[n]=1ll;
        f2[n]=0ll;
        for(int i=n-1;i>=1;i--){
            if(r[i]==i) continue;
            if(r[i]==i+1){
                f1[i]=1ll;
                //for(int j=r[r[i]-1]+1;j<=r[r[i]];j++){
                //    ans+=1ll*f2[j];
                //    f2[i]+=1ll*f2[j];
                //}
                if(r[r[i]-1]+1==r[r[i]]){
                    ans+=1ll*f2[r[r[i]]];
                    f2[i]+=1ll*f2[r[r[i]]];
                }else if(r[r[i]-1]+1<r[r[i]]){
                    ans+=1ll*f2[r[r[i]]];
                    f2[i]+=1ll*f2[r[r[i]]];
                    ans+=1ll*f1[r[r[i]]-1];
                    f2[i]+=1ll*f1[r[r[i]]-1];
                }
                if(r[r[i]-1]+1<=r[r[i]]){
                    f1[i]+=1ll*f1[r[r[i]]];
                }

                //for(int j=r[r[i]-1]+1;j<=r[r[i]];j++){
                //    f1[i]+=1ll*f1[j];
                //}
                continue;
            }
            //r[r[i]-2]+1 
            //r[r[i]-1] 
            
            //for(int j=r[r[i]-2]+1;j<=r[r[i]-1];j++){
            //    ans+=1ll*f1[j];
            //    f2[i]+=1ll*f1[j];
            //}


            if(r[r[i]-2]+1<=r[r[i]-1]){
                ans+=1ll*f1[r[r[i]-1]];
                f2[i]+=1ll*f1[r[r[i]-1]];
            }

            //r[r[i]-1]+1 
            //r[r[i]] 
            
            
            //for(int j=r[r[i]-1]+1;j<=r[r[i]];j++){
            //    ans+=1ll*f2[j];
            //    f2[i]+=1ll*f2[j];
            //}
            if(r[r[i]-1]+1==r[r[i]]){
                ans+=1ll*f2[r[r[i]]];
                f2[i]+=1ll*f2[r[r[i]]];
            }else if(r[r[i]-1]+1<r[r[i]]){
                ans+=1ll*f2[r[r[i]]];
                f2[i]+=1ll*f2[r[r[i]]];
                ans+=1ll*f1[r[r[i]]-1];
                f2[i]+=1ll*f1[r[r[i]]-1];
            }

            
            //for(int j=r[r[i]-1]+1;j<=r[r[i]];j++){
            //    f1[i]+=1ll*f1[j];
            //}


            if(r[r[i]-1]+1<=r[r[i]]){
                f1[i]+=1ll*f1[r[r[i]]];
            }

            //ans+=1ll*(r[r[i]-1]-(r[r[i]-2]+1)+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}