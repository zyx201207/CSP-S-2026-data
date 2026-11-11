#include<bits/stdc++.h>
using namespace std;
int c,t,n,sums;
long long d,a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-3;i++)
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i]>d)
				sums++;
		cout<<sums<<endl;
		sums=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

