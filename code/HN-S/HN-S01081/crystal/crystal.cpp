//half ans

#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;

long long n,m;

long long a[N],pre[N];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if((n==1) || (m==0)) return cout<<1,0;
	
	sort(a+1,a+n+1);
	
	long long ans=1;
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		
		long long l=1,r=i,mid=0;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	
	cout<<ans;
	
	return 0;
}
