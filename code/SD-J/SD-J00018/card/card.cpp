#include<bits/stdc++.h>
using namespace std;
void _file(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
int n,m;//5e5,3e5
bool tmpfl=1;
long long v[300010],user;
int tong[300010];
long long ans[300010],a[300010];
int main(){
	_file();
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=user&&tmpfl){
			tong[a[i]]++;
			user=a[i];
		}else tmpfl=0;
		v[a[i]]=i;
	}
	if(tmpfl){
		long long fusum=0;
		for(int i=1;i<=m;i++){
			fusum+=tong[i];
			cout<<fusum<<' ';
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long tp=i;
		while(tp<=n){
			ans[a[tp]]++;
			tp=v[a[tp]]+1;
		}
	}
	for(long long i=1;i<m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<ans[m];
	return 0;
}


