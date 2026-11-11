#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int n,m,a[500005],s[500005];
deque<int> q;
int cal(int i,int l){
    return 1;
}
bool cmp(int a,int b){return a<b;}
bool check(int k){
    int res=LLONG_MAX;
    //cout<<"current k:"<<k<<"\n";
    for(int r=k;r<=n;r++){
        int val=(k-1)*a[r]-(s[r-1]-s[r-k]);
        //cout<<"current r:"<<r<<"    val:"<<val<<"\n";
        res=min(res,val);
    }
    return res<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int lft=0,rgt=n+1;
    while(lft+1<rgt){
        int mid=(lft+rgt)/2;
        if(check(mid))lft=mid;
        else rgt=mid;
    }
    //cout<<(n-1)*a[n]-s[n-1]<<"\n";
    cout<<lft<<"\n";
    return 0;
}
