#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500017],s[500017],qz[500017],cnt=0,mx=0,l=2,r=1,tot=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		qz[i]=qz[i-1]+s[i];
	}
	while(r!=n){
		while(1){
			r++;
			cnt++;
			if(tot<=m-s[r]*cnt){
				tot+=s[r]*cnt;
			}else{
				r--;
				cnt--;
				break;
			}
			if(r==n) break;
		}
		mx=max(mx,r-l+1);
		if(r==n) break;
		l++;
		cnt--;
		tot-=(qz[r]-qz[l-2]);
	}
//	for(int i=2;i<=n;i++){
//		s[i]=s[i]*(i-1);
//		if(m-s[i]>=0){
//			m-=s[i];
//			cnt++;
//		}else{
//			break;
//		}
//	}
	cout<<mx+1<<endl;
	return 0;
}
 