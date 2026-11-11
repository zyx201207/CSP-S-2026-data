#include <bits/stdc++.h>
using namespace std;
long long n,m;
int ans=1;
int a[10000005],b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<n;i++){
		if(m==0) break;
		if(a[i]-a[i-1]<=m){
			if(b[i-1]==0){
			a[i-1]=a[i];
			m=m-a[i]+a[i-1];
			b[i]++;
			b[i-1]++;
		}
		else{
			int o=0;
			for(int j=1;j<i;j++){
				if(b[j]!=0){
					o+=a[i]-a[j];
				}
			}
			if(o<=m){
				m-=o;
				for(int q=1;q<i;q++){
					if(b[q]!=0){
						a[q]=a[i];
					}
				}
				b[i]++;
			}
		}
		}
	}
	for(int i=1;i<=n;i++){
	 	if(a[i]==a[i+1]){
	 		ans++;
		 }
	 }
	 cout<<ans;
}
