#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],d,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1)d=a[i+1]-a[i],f=1;
		else{
			if(a[i]-a[i-1]!=d){
				f=0;
				break;
			}
		}
	}
	if(f==1){
		m/=d;
		int i=0;
		while(m>=0){
			m-=i;
			ans++;
			i++;
		}
		if(m<0)ans--;
	}
	else{
		for(int i=n;i>=1;i--){
			int id=i,t=0;
			long long sum=m;
			while(id>0){
				if(sum>=a[i]-a[id]){
					sum-=a[i]-a[id];
					t++;
					id--;
				}
				else break;
			}
			ans=max(ans,t);
		}
	}
	cout<<min(ans,n);
} 
