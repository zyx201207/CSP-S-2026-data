#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,sum=0,num=99999;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n/2;i++){
		sum+=a[i];
		long long nn=0;
		for(int j=i-1;j<=m;j++){
			nn+=a[j];
		}
		num=min(num,nn);
	}
	cout<<sum<<" "<<a[1]<<" "<<num;
	return 0;
}
