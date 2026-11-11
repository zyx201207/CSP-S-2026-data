#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=1;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=ans and a[n-i];
	}
	cout<<ans; 
	return 0;
} 
