#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s;
int main(){
	freopen("ctystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]<=m){
			m-=(a[i]-a[i-1]);
			a[i]=a[i-1];
			s++;
		}
	}
	cout<<s;
	return 0;
}

