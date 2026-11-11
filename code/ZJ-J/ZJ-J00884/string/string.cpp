#include<bits/stdc++.h>
#define int long long
#define ull long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define N 100000
#define M 100000
#define inf 1000000000
#define pii pair<int,int>
#define endl "\n"
using namespace std;

int n,a[N],b[N],sb[N];
char c[N],d[N];
int tmp,tmp2;
int sz1,sz2;
int ss=0,p=0,typ=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int sum=0,xx=0;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        if(y==c[xx]){
            a[xx]+=x;
        }
        else{
            c[++xx]=y;
            a[xx]=x;
        }
        sum+=x;
    }
    n = xx;
    for(int i=1;i<=n;i++){
        ss+=a[i];
        if(ss==sum/2){
            p=i;
            typ=1;
            break;
        }
        if(ss>sum/2){
            p=i;
            int tt=a[i];
            a[i]=sum/2-(ss-a[i]);
            tmp=tt-a[i]-sum%2ll;
            break;
        }
    }
    if(typ){
        for(int i=n;i>=p+1;i--){
       b[n-i+1]=a[i];
       d[n-i+1]=c[i]; 
    };sz1=p,sz2=n-p;}
    if(typ==0){
        b[n-(p+1)+2]=tmp;
        d[n-(p+1)+2]=c[p];
        int sz1=p,sz2=n-p+(b[n-(p+1)+2]!=0);
        if(a[p]==0){
            sz1--;
        }
    }
    int sa=0,ans=0;
    for(int i=1;i<=sz2;i++)sb[i]=sb[i-1]+b[i];
    for(int i=1;i<=sz1;i++){
        int l=sa;
        int r=sa+a[i];
        sa+=a[i];
        int pu=lower_bound(b+1,b+sz2+1,r)-b;
        int pd=lower_bound(b+1,b+sz2+1,l)-b;
        for(int j=pd+1;j<=pu;j++){
            if(j==pd+1){
                if(d[j]!=c[i]){
                    ans+=sb[pd+1]-l+1;
                }
                continue;
            }
            else if(j==pu){
                if(d[j]!=c[i]){
                    ans+=r-sb[pu]+1;
                }
                continue;
            } else{
                if(d[j]!=c[i]){
                    ans+=b[j];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}