#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int b[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int aa=a[1];
	if(a[1]<0)aa=-a[1];
	
	for(int i=1;i<=n;i++){
		b[a[i]+aa+1]++;
	}
	
	int o=0,oo=0;
	for(int i=1;i<=a[n];i++){
		if(b[i]>o){
			o=b[i];
			oo=i-aa-1;
		}
	}
	int ans=0;
	
	if(o==1){
		for(int i=0;i<n;i++){
			m-=(a[i+1]-a[i]);
			if(m<0)break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		a[i]-=oo;
	}
	for(int i=1;i<=n;i++){
		int h=1;
		if(a[i]<0)a[i]=-a[i];
		if(a[i]==0){
			ans++;
			continue;
		}
		if(a[i]>0){
			h=i-1;
			a[i]=i-1;
		}
		m-=a[i]*h;
		
		if(m<0){
			break;
		}
		
		ans++;
	}
	cout<<ans;
	
	
	return 0;
} 
