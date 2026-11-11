#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,t,l;
	t=0;l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		t=a[1];
		for(int i=2;i<=n;i++){
			t=(t&a[i]);
		}
		cout<<t;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			t=max(t,a[i]);
		}
		cout<<t;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				l=(a[i]&a[j]);
				t=max(t,l);
			}
		}
		cout<<t;
	}
	else{
		sort(a+1,a+n+1);
		t=a[n];
		for(int i=2;i<=m;i++){
			t=(t&a[n-i+1]);
		}
		cout<<t;
	}
	return 0;
}
