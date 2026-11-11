#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		int sum=0;
		for(int j=i;j<=m;j++){
			int z=a[j],num,w=1;
			while(z!=0){
				num+=w*z%2;
				z/=2;
				w*=10;
			}
			sum=sum & num;
		}
		if(sum>maxn) maxn=sum;
	}
	cout<<maxn;
	return 0;
}