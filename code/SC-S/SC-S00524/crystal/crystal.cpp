#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int cnt=0;
		for(int j=1;j<i;j++){
			int jj=a[j];
			int ii=a[i];
			cnt+=ii-jj; 
		}
		if(m<cnt){
			cout<<i-1;
			break;
		}
	}
	return 0;
} 