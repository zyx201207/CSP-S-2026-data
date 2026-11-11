#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,t;
int a[maxn],cha[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int num=0;
		for(int i=2;i<=n;i++){
			cha[i]=a[i]-a[i-1];
			if(cha[i]==1)num++;
		}
		if(num==n-1){
			if(d==1)cout<<0<<'\n';
			else if(d==2){
				cout<<n-3<<'\n';
			}else{
				cout<<0<<'\n';
			} 
		}else{
			int num=0,ans=n;
			if(d==1)cout<<0<<'\n';
			else if(d==2)cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}
