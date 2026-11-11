#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ida,idb;
char b[200005];
long long cnta,cntb,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	cnta+=a[1];
	ida=1;
	idb=n+1;
	while(ida<n){
		while(cntb+a[idb-1]<=cnta){
			idb--;
			cntb+=a[idb];
			if(b[idb]!=b[ida]){
				ans+=a[idb];
//				cout<<ans<<"\n";
			}
		}
		if(b[idb-1]!=b[ida]){
			ans+=cnta-cntb;
		}
		idb--;
		cntb+=a[idb];
		while(cnta+a[ida+1]<=cntb){
			ida++;
			if(b[ida]!=b[idb]){
				ans+=a[ida];
			}
			cnta+=a[ida];
		}
		if(cnta!=cntb){
			if(b[ida+1]!=b[idb]){
				ans+=cntb-cnta;
			}
			ida++;
			cnta+=a[ida];
		}
	}
	if(cnta!=cntb){
		while(cntb+a[idb-1]<cnta){
			idb--;
			cntb+=a[idb];
			if(b[idb]!=b[ida]){
				ans+=a[idb];
//				cout<<ans<<"\n";
			}
		}
		if(b[idb-1]!=b[ida]){
			ans+=cnta-cntb;
		}
		idb--;
		cntb+=a[idb];
	}
	cout<<ans/2;
	return 0;
}

