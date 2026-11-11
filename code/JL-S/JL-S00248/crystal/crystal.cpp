#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
            int cnt=1;
            long long cst=0;
        for(int j=1;i-j>=1;j++){
            long long us=m-cst,tus=a[i]-a[i-j];
            if(us>=tus){
                cst+=tus;
                cnt++;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

