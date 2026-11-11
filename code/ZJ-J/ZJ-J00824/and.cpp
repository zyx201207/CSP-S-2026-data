#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	k=a[1];
	for(int i=2;i<=m;i++){
		k&=a[i];
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

