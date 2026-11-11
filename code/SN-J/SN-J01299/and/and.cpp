#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0,num;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			num=min(a[i],a[j]);
			sum=max(sum,num);
		}
	}
	cout<<sum;
	return 0;
}
