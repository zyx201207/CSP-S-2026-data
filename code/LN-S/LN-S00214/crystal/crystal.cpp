#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    int64_t m;
    cin>>n>>m;
    //cout<<n<<' '<<m<<endl;
    int s;
    long long a[500005];
    __int128 sum=0;

    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum=sum+a[i];
        if(sum+m>=(__int128)((__int128)a[i]*(__int128)i))ans=i;
        else break;

    }
    cout<<ans;
}

