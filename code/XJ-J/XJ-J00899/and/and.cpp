#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10005],b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b=max(a[i],b);
	}
	cout<<b;
	fclose(stdin);
    fclose(stdout);
	return 0;
}