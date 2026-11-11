#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[10000004];
int b[10000004];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max((a[i]&a[j]),ans);
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		if(a[1]!=1){
			sort(a,a+n);
			cout<<a[n-m];
			return 0;
		}
		else{
			int x=n;
			for(int i=0;i<m;i++){
				b[i]=a[x];
				x-=2;
			}
			for(int i=0;i<m;i++){
				cout<<(b[1+i]&b[++i]);
			}
			return 0;
		}
		
	}
	
	return 0;
}