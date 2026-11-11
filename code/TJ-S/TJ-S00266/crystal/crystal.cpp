#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n;
long long m,a[N],op=0; 
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,ans=1;
    for(int i=1;i<n;i++){
        while((a[i+1]-a[i])*(i-l+1)>m-op&&l<i){
            op-=(a[i]-a[l]);
            l++;
        }
        if(l==i&&a[l+1]-a[l]>m){
            l++;
        }else{
            op+=(a[i+1]-a[i])*(i-l+1);
            ans=max(ans,i-l+2);
        }
    }
    cout<<ans<<endl;
    return 0;
}
