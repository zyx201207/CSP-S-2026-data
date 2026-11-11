#include<bits/stdc++.h>
using namespace std;
int n,ans,mid;
long long m,sum,minn=1000000000001,jz;
int a[100005],b[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        minn=min(abs(a[i]-sum/n),minn);
    }
    jz=sum/n+minn;
    for(int i=1;i<=n;i++){
        b[i]=jz-a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(b[i]>=0){
            if(m>=b[i]){
                m-=b[i];
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
