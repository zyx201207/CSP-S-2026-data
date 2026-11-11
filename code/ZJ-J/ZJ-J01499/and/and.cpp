#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
	}else{
		if(m==1){
			sort(a+1,a+1+n);
			cout<<a[n];
		}else{
			if(m==2){
				long long mx=0;
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						int o=a[i];
						o&=a[j];
						if(o>mx){
							mx=o;
						}
					}
				}
				cout<<mx;
				
		}else{
			cout<<7;
		}
	}
	
}
	return 0;
}
