#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long num[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){cout<<1;return 0;}
    sort(a,a+n);
    bool flag=1;
    for(int i=1;i<n;i++){
        num[i]=a[i]-a[i-1];
        if(i>1&&num[i]!=num[i-1]){
            flag=0;
        }
    }
    if(flag){
        cout<<int(sqrt(2*m/num[1]));
        return 0;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long cost=0;
        long long c=0,cnt=i;
        for(cnt=i;cost<=m&&cnt>=0;cnt--){
            c+=num[cnt];
            cost+=c;
        }
        ans=max(i-cnt,ans);
    }
    cout<<ans;
    return 0;
}
