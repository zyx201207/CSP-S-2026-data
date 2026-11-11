#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ma=-1;
	cin>>n>>m;
	int r=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++)
		{
			int k=a[i]&a[j];
			//cout<<k<<endl;
			if(k>ma)ma=k;
		}
	}
	cout<<ma;
	return 0;
}
