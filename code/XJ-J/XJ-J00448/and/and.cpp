#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long jl,da1=-1,da2=-1,da3=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>da1) da1=a[i];
		if(a[i]>da2&&a[i]<da1) da2=a[i];
		if(a[i]>da3&&a[i]<da2) da3=a[i];
	}
	jl=da1&da2&da3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}