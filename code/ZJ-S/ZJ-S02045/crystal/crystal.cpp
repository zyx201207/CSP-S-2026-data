#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],pre[N];
bool check(int i,int mid){
	int len=i-mid+1;
	return pre[i]-pre[mid-1]+m>=a[i]*len;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(i,mid))r=mid;
			else l=mid+1;
		}
//		cout<<"len"<<i<<' '<<i-r+1<<endl;
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}
