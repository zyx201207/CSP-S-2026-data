#include<bits/stdc++.h>
using namespace std;
int cnt[500010][31];
bool f[500010];
int a[500010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
	}
	for(int i=1;i<=n;i++){
		int id=0;
		while(a[i]>0){
			id++;
			cnt[i][id]=a[i]%2;
			a[i]/=2;
//			cout<<i<<' '<<id<<' '<<cnt[i][id]<<endl;
		}
	}
	long long ans=0;
	bool flag=0;
	for(int i=31;i>=1;i--){
		int ret=0;
		for(int j=1;j<=n;j++){
			if(cnt[j][i]==1&&f[j]){
				ret++;
//				cout<<"!1"<<' '<<j<<endl;
			}
		}
//		cout<<i<<' '<<ret<<endl;
		if(ret>=m){
//			cout<<1111111;
			ans+=pow(2,(i-1));
			for(int j=1;j<=n;j++){
				if(cnt[j][i]==0){
					f[j]=0;
//					cout<<j<<' '<<endl;
				}
			}	
			flag=1;
			
		}
	}
	cout<<ans;
	return 0;
}
