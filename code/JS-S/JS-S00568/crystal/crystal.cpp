#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back

const int N=5e5+9;
int lowbit(int x){return x&(-x);}
void chkmin(int &x,int y){x=x<y?x:y;}
void chkmax(int &x,int y){x=x>y?x:y;}
void chkmin(ll &x,ll y){x=x<y?x:y;}
void chkmax(ll &x,ll y){x=x>y?x:y;}

#define int long long
int n,m,a[N],pre[N],ans=0;
void Mian(int TestCase){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int L=1,R=n,res=n;
        while(L<=R){
            int mid=L+R>>1;
            int ret=pre[i]-pre[mid-1],len=i-mid+1;
            if(len*a[i]-ret<=m) R=(res=mid)-1;
            else L=mid+1;
        }
        chkmax(ans,i-res+1);
    } cout<<ans;
}
void Mianclr(){

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int c=0,T=1; //cin>>T;
    while(T--){
        Mian(c);
        Mianclr();
    }
}
