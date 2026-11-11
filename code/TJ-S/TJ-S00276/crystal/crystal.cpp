#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(long long i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			f=false;
			cnt=i;
			break;
		}
	}
	if(!f) sort(a+cnt,a+n+1);
	long long i=1;
	for(i=1;i<=n;i++){
		if((a[i+1]-a[i])*i<=m) m-=(a[i+1]-a[i])*i;
		else break;
	}
	cout<<i;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
