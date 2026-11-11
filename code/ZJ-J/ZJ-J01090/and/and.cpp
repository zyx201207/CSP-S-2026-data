#include<bits/stdc++.h>

using namespace std;

const int N=2e5+3;

int n,m;
long long a[N];
long long ans=0;

long long ts[N];

void bl(int now,long long sum,int lst){
	if((now-1)+(n-lst)<m) return;
	if(sum==0) return;
	if(now>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=lst+1;i<=n;i++){
		if(sum==-1) bl(now+1,a[i],i);
		else bl(now+1,sum&a[i],i);
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long mx=a[1];
		for(int i=2;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			ts[i]=-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(ts[j]!=-1) ts[j]=ts[j]&a[i];
				else ts[j]=a[i];
			}
		}
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,ts[i]);
		}
		cout<<mx;
		return 0;
	}
	
	if(n<=2000){
		bl(1,-1,0);
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	
	return 0;
}
