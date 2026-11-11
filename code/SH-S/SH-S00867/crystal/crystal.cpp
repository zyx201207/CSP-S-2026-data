#include <bits/stdc++.h>
using namespace std;
#define int long long
//EZ! 
int a[1000000],q[1000000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];	
	}
	int l=1,r=n;
	while(l<=r){
		//cout<<"mid="<<(l+r)/2<<" ";
		int mid=(l+r)/2;
		bool ok=0;
		for(int i=mid;i<=n;i++){
			if(a[i]*(mid-1)-(q[i-1]-q[i-mid])<=m){
				ok=1;	
				break;
			}
		}
		if(ok){
		//	cout<<"ok"<<endl;
			l=mid+1;	
		}else{
			//cout<<"nok"<<endl;
			r=mid-1;
		}
	}
	cout<<l-1<<endl;
	return 0;
}
