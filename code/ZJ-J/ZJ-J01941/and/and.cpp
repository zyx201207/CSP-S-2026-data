#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],cnt,zd;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	if(m==1) cout<<zd;
	if(m==2){
		long long s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[j]&a[i]);
			}
		}
		cout<<s;
	}
	if(m==n){
		long long s=a[1];
		for(int i=2;i<=m;i++){
			s&=a[i];
		}
		cout<<s;
	}else{
		long long s=0,as=0;
		for(int i=1;i<=n;i++){	
			s=a[i];
			for(int j=1;j<m;j++){
				s&=a[i+j];
			}
			as=max(s,as);
		}
		cout<<as;
	}
	return 0;
}