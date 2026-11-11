#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m,a[500005],T1=1,ans,z;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1]>>a[2];
	z=m;
	if(n==1)T1=0;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])T1=0;
	}
	sort(a+1,a+1+n);
	if(T1){
		int c=a[2]-a[1],j=0,i=0;
		while(j<m and i<n){
			i++;
			j+=i*c;
		}
		if(j>m){
			cout<<i;
		}else{
			cout<<i+1;
		}
	}else{
		for(int i=a[1];i<=a[n];i++){
			m=z;
			int b,cnt=0;
			for(int j=1;j<=n;j++){
				if(a[j]>i){
					b=j-1;
					break;
				}
				
			}
			for(int j=b;j>=1;j--){
				
				
				//cout<<j<<' ';
				//cout<<m <<' ';
				if(m>=i-a[j]){
					//cout<<j<<' ';
					m-=(i-a[j]);
					cnt++;
				}else break;
			}
			//cout<<cnt<<endl;
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
