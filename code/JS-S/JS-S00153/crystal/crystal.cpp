#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

int n;
long long m,a[maxn],suma[maxn];

bool check(int x){
    for(int l=1;l<=n-x+1;l++){
        int r=l+x-1;
        long long cost=(x-1)*a[r]-(suma[r-1]-suma[l-1]);
        if(cost<=m)
			return 1;
    }
    return 0;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    //cout<<676767<<'\n';
    for(int i=1;i<=n;i++){
        suma[i]=suma[i-1]+a[i];
    }

    int l=1,r=n+1,ans=0;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){
			ans=mid;
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<ans;
    return 0;
}
