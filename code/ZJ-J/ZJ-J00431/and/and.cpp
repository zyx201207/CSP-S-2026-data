#include <bits/stdc++.h>
using namespace std;
long long a[200020][32],c[200200],ans[200];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long q;
		cin>>q;
		int j=1;
		while(q){
			a[i][j++]=q%2;
			q/=2;
		}
	}
	for(int k=30;k>0;k--){
		int sum=0;
		for(int i=1;i<=n;i++)if(a[i][k] && !c[i])sum++;
		if(sum<m)continue;
		ans[k]=1;
		for(int i=1;i<=n;i++)if(!a[i][k])c[i]=1;
	}
	long long num=0,b=1;
	for(int i=1;i<=30;i++){
		num+=b*ans[i];
		b*=2;
	}
	cout<<num;
	return 0;
}

