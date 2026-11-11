# include <bits/stdc++.h>
# define int long long
using namespace std;
int ans=0,q=1e9;
struct NODE{
    int num;
    char zf;
};
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<NODE>a(n+10);
    vector<int>b(n+10,0);
    int q=n,ne=0,f=1;
    cin>>a[1].num>>a[1].zf;
    while(q>1){
        int x;
        char y;
        cin>>x>>y;
        if(y==a[f].zf){
            a[f].num+=x;
            ne++;
        }
        else{
            f++;
            a[f].num=x;
            a[f].zf=y;
        }
        q--;
    }
    n=n-ne;
    for(int i=1;i<=n/2;i++){
        int k=n-i+1;
        if(a[i].num!=a[k].num) b[i]=abs(a[i].num-a[k].num);
        if(a[i].zf!=a[k].zf) ans+=a[i].num;
    }
    for(int i=2;i<=n;i++){
        b[i]=min((abs(b[i-1]-b[i])),abs(b[i-1]+b[i]));
    }
    ans+=b[n]*2;
    cout<<ans;
}
