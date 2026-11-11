#include<bits/stdc++.h>
using namespace std;
#define int long long
unsigned long long d;
int n,cnt;
int a[2000005];
int l[2000005];
int r[2000005];
void ttt(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    int j=1;
    for(int i=1;i<=n;i++){
        while(j<=n&&a[j]-a[i]<=d) j++;
        j--;
        if(a[i+1]-a[i]>d) r[i]=-1e18;
        else r[i]=j;
        j++;
    }
    j=n;
    for(int i=n;i>=1;i--){
        while(j>=1&&a[i]-a[j]<=d) j--;
        j++;
        if(a[i]-a[i-1]>d) l[i]=1e18;
        else l[i]=j;
        j--;
    }
    cnt=0;
    //for(int i=1;i<=n;i++) cout<<l[i]<<' ';
    //cout<<'\n';
    //for(int i=1;i<=n;i++) cout<<r[i]<<' ';
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        int ll=i+1,rr=n,mid;
        while(ll<=rr){
            mid=(ll+rr)/2;
            if(r[i]-l[mid]+1>2){
                ll=mid+1;
            }else if(r[i]-l[mid]+1==2){
                //cout<<i<<' '<<mid<<'\n';
                cnt++;
                rr=mid-1;
            }else{
                rr=mid-1;
            }
        }
    }
    cout<<cnt<<'\n';
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) ttt();
    return 0;
}
