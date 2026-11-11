#include<bits/stdc++.h>
using namespace std;
int a[100005],pre[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	pre[1]=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	long long zd=0;
	for(int i=1;i<=n-m;i++){
		for(int j=m+1;j<=n;j++){
			if(pre[j]-pre[i]>zd) zd=pre[j]-pre[i];
		}
	}
	cout<<zd;
	return 0;
}
