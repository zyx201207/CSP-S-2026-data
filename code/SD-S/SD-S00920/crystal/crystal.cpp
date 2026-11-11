#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m;
int n,ans;
long long a[N],s[N];
void solve(int L,int R,int pos){
	while(L<=R){	
		int mid=(L+R)/2;
		long long sum=1LL*a[pos]*(pos-mid)-(s[pos-1]-s[mid-1]);
		if(sum<=m){
			R=mid-1;
			ans=max(ans,pos-mid+1);
		}else{
			L=mid+1;
		}
	}
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		solve(1,i,i);
	cout<<ans;
	
	return 0;
} 
