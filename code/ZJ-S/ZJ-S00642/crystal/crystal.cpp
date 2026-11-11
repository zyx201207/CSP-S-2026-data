#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500100;
int n,m,a[N],c[N],sum=0,ans=0;
queue<int>q;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
    int num=1;
    for(int i=2;i<=n;i++){
    	q.push(c[i]);
    	sum=sum+c[i]*num;
    	num++;
    	while(sum>m) sum-=a[i]-q.front(),q.pop(),num--;
    	ans=max(num,ans);
	}
	cout<<ans;
    return 0;
}