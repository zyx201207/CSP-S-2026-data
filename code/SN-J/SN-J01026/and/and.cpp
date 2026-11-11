#include<bits/stdc++.h>
usingnamespace std;
long long n,m,a[1000001];
int main(){
	//freopen("and.in","r",stdin);
	//feoprn("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==n/2+1){
			cout<<a[i];
		}
	}
	return 0;
}
