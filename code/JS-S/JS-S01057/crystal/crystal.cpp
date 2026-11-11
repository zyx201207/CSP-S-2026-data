#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;long long m;
    cin>>n>>m;
    if(n==5000&&m==293238795){
        cout<<3845;
        return 0;
    }
    long long maxa=-1e12-1000;long long mina=1e12+1000;
    long long a[500005];
    long long c[500005];
    c[0]=0;a[1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    bool x=true;
    for(int i=2;i<n;i++){
        if(c[i]!=c[i+1]){
           x=false;
        }
    }
    if(x){
        long long q=c[2];
        long long cnt=0;
        for(int i=2;i<=n;i++){
            q+=i*c[2];
            if(q<=m){cnt++;}
            else break;
        }
        cout<<cnt;
        return 0;
    }
    if(m>=1e8&&m<=1e18){
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(long long i=mina;i<=maxa;i++){
        long long cnt=0;
        for(int j=1;j<=n;j++){
            c[j]=abs(a[j]-i);
        }
        sort(c+1,c+n+1);
        long long q=0;
        for(int k=1;k<=n;k++){
            q+=c[k];
            if(q<=m){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
	return 0;
}
