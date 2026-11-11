#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f=max(f,(a[i]&a[j]));
			}
		}
		cout<<f;
		
	}
	else if(m==n){
		f=a[1];
		for(int i=2;i<=n;i++){
			f=(f&a[i]);
		}
		cout<<f;
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	return 0;
}
