#include<bits/stdc++.h>
using namespace std;
const int N=2e+5;
int a[N+10];
int c[N+10];
long long n,m; 
bool mz_a(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return 0;
	}
	return 1;
}
bool mz_b(){
	int cz=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cz) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(mz_a()){
		long long sum=0;
		int i;
		bool flag=1;
		for(i=1;i<=n;i++){
			sum+=i-1;
			if(sum>m){
				flag=0;
				break;
			}	
		} 
		if(flag==0) cout<<i-1;
		else cout<<n;
		
	}else if(mz_b()){
		sort(a+1,a+n+1);
		long long sum=0;
		int i;
		bool flag=1;
		int gc=a[2]-a[1];
		for(i=1;i<=n;i++){
			sum+=(i-1)*gc;
			if(sum>m){
				flag=0;
				break;
			}	
		} 
		if(flag==0) cout<<i-1;
		else cout<<n;
		
	}else{
		sort(a+1,a+n+1);
		
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				c[i]+=a[i]-a[j];	
			}
			if(c[i]<=m){
				mx=max(mx,i);
			}
		}
		
		cout<<mx;
	}
	
	
	return 0;
}