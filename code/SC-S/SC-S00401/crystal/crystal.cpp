#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			long long f_ans=0,f_max=0,f_xb;
			a[i]+=j;
			for(int i=1;i<=n;i++){
				for(int j=1;j<n;j++){
					if(a[i]==a[i]+j)f_max++;
				}
			} 
			if(f_max>f_ans){
				f_ans=f_max;
				f_xb=j;
			}
			m-=f_xb;
			ans=f_ans;
		}
	}
	cout<<ans;
	return 0;
 }