#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,sum=0,ans=0;
    long long minn=1000000000000;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(m!=0){
                a[j]++;
                m--;
            }
        }
    }for(int i=1;i<=n;i++){
        sum=0;
        for(int j=i;j<=n;j++){
            if(a[i]==a[j]){
                sum++;
            }
        }ans=max(ans,sum);
    }cout<<ans;
    return 0;
}

