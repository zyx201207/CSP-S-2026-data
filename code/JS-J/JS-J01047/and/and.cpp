#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long ans=0;
				ans=a[i]&&a[j];
				cnt=max(cnt,ans);
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
	}
	bool f=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			f=0;
		}
	}
	if(f){
		cnt=a[1];
		for(int i=1;i<=m;i++){
			cnt=cnt&&a[1];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
