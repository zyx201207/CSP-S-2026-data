#include<bits/stdc++.h>
using namespace std;
long long a[5*100000+10]; 
int main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	long long n,m,maxx=-99999,tmp=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//		cout<<m
//	}
	while(true){
		if(m<=0) break;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]<a[i+1]){
				m-=(a[i+1]-a[i]);
				if(m<0) break;
				a[i]=a[i+1];
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			if(a[i-1]==a[i]) tmp++;
			maxx=max(maxx,tmp);
//			cout<<tmp<<" ";
			tmp=0;
		}
		else tmp++;
//		cout<<a[i]<<" ";
	}
	cout<<maxx;
	//Oct31==Dec25? 
	return 0;
	}
}
