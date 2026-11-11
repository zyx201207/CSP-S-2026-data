#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],m;
int main(){
	freopen("end.in","r",stdin);
	freopen("end.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cout<<a[n-1];
} 
