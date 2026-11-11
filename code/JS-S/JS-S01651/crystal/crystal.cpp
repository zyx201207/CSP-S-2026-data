#include<bits/stdc++.h>
using namespace std;
int n,l,maxx=-1;
long long m,a[500015],sum;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    l=1;
    for(int i=1;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m){
            sum-=a[i]-a[l];
            l++;
        }
        maxx=max(maxx,i-l+1);
	}
    cout<<maxx;
    return 0;
}
