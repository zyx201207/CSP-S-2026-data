#include<bits/stdc++.h>
using namespace std;
long long a[600005],b[600005];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+a[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+a[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<' ';
//	}
	long long l=0,r=0;
	long long ans=0;
	
	for(l=0;l<=n;l++){
		m+=a[r]-a[l];
		while(m-(a[r+1]-a[r+1-1])*(r+1-l+1)>0&&r<n){
			r++;
			m-=(a[r]-a[r-1])*(r-l+1);		
//			cout<<l<<' '<<r<<' '<<m<<endl;
		}
		ans=max(ans,r-l+1);
	}
//	cout<<l<<' '<<r<<endl;
//	cout<<m<<endl;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
