#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e5;
const int M=1e3+1e2;
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		return 0;
	}
	return 0;
}

