#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int v[N];
int sum=0;
int yu(int a,int b){
	int ci=0;
	int jia=0;
	while(a!=0&&b!=0){
		if(a%2==1&&b%2==1){
			long long s=1;
			for(int i=1;i<=ci;i++){
				s*=2;
			}
			jia+=s;
		}
		a/=2;
		b/=2;
		ci++;
	}
	return jia;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(n<=20){
		int maxx=-0x3f3f3f3f3f3f3f3f;
		int shu=0;
		for(int i=0;i<1<<n;i++){
			int t=i;
			int cnt=0;
			sum=0;
			shu=0;
			for(int j=1;j<=n;j++){
				if(t%2==1){
					shu++;
					if(cnt!=0){	
						cnt=yu(v[j],cnt);
					}
					if(cnt==0){
						cnt=v[j];
					}
				}
				t/=2;
			}
			if(shu==k){
				maxx=max(maxx,cnt);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(k==1){
		int maxx=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,v[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(k==2){
		int maxx=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int jieguo=yu(v[i],v[j]);
					maxx=max(maxx,jieguo);
				} 
			}
		}
		cout<<maxx;
		return 0;
	}
	if(k==n){
		int cnt=v[1];
		for(int i=1;i<=n;i++){
			cnt=yu(cnt,v[i]);
		}
		cout<<cnt;
		return 0;
	}
	if(k==n-1){
		int cnt=0;
		int maxx=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(cnt==0){
						cnt=v[j];
					}else{
						cnt=yu(cnt,v[j]);
					}
				}
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	else{
		sort(v+1,v+1+n);
		cout<<v[n-k+1];
		return 0;
	}
	return 0;
}
