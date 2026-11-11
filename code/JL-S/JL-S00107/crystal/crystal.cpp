#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int t=1,n;
	cin>>n>>m;
	b[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	for(int i=n;i>=1;i--){
		int r=0,l=i-1,j;
		while(l-r>1){
			j=(r+l)/2;
			if(a[i]*(i-j+1)-b[i]+b[j-1]<=m) l=j;
			if(a[i]*(i-j+1)-b[i]+b[j-1]>m) r=j;
		}
		t=max(t,i-l+1);
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
