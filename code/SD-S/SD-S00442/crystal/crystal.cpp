#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=1e5+10;
long long n,m,g[N],ff[N],f[N],c[N],cnt,a[N],lg[90],ans=0,ll[N];
int main(){
 //   freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a[0]=1e12+10;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=a[n]+1;
    for(int i=1;i<=n;i++){
        if(a[i-1]!=a[i]){
            cnt++;
            f[cnt]++;
            g[cnt]=a[i];
        }
        else f[cnt]++;
    }
    for(int i=2;i<=10;i++){
        ll[i]=ll[i>>1]+1;
    }
    lg[0]=1;
    for(int i=1;i<=62;i++){
        lg[i]=lg[i-1]*2; 
        lg[i-1]--;
    }
    lg[62]--;
    for(int i=1;i<=cnt;i++){
        if(f[i-1]==0)c[i]=0;
        if(f[i-1]>=1)c[i]=lg[a[i]-a[i-1]];
    }
    for(int i=1;i<=n;i++){
        long long m1=m,cc=0,l=i-1,r=1,q=0;
        while(1){	
            l++;
            m1++;
            cc+=max(lg[a[l]-a[i]],(long long)1);
            if(lg[ll[cc]]==cc)
            q=lg[ll[cc]];
            else q=lg[ll[cc]]+1;
            ans=max(ans,m1-m);
            cout<<ans<<' ';
            cout<<cc<<' '<<q<<endl;
            if(m1<q||l>n)break;
        }
    }
    cout<<ans;
    return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
