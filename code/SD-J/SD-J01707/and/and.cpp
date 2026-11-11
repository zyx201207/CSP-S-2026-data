#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-0x3f;
bool check(){
	int t=n,f=0;
	while(t!=0){
		if(t%2==1){
			f++;
		}
		t/=2;
	}
	if(f!=1){
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=(i-1)){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long t=(a[i]&a[j]);
				if(t>maxx) maxx=t;
			}
		}
		cout<<maxx;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}else if(n<=20){
		long long ans=-1; 
		for(int i=1;i<(1<<n);i++){
			int t=i,cnt=1,f=0;
			long long now;
			int flag=0;
			while(t!=0){
				if(t%2==1&&f==0){
					now=a[cnt];
					f=1;
				}
				if(t%2==1&&f==1){
					now=(now&a[cnt]);
				}
				if(t%2==1) flag++;
				cnt++;
				t/=2;
			}
			if(now>ans&&flag==m){
				ans=now;
			}
		}
		cout<<ans; 
	}else if(check()){
		long long ans=a[n];
		m--;
		for(int i=n-1;i>=1;i--){
			if(m==0) break;
			ans=(ans&a[i]);
			m--;
		}
		cout<<ans;
	}else if(m==n-1){
		long long t=a[1];
		for(int i=2;i<=n;i++){
			t=(t&a[i]);
		}
		long long ans=-1;
		for(int i=1;i<=n;i++){
			long long temp=(t&a[i]);
			if(temp>ans){
				ans=temp;
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
