#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],q[500005];
long long ans;
long long num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		num=i*a[i];
		if(num-q[i]>m){
			cout<<num-q[i];
			ans=i-1;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
