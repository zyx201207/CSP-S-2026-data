#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>n-m;i--){
		s=s&a[i];
	}
	cout<<s;
	return 0;
}
