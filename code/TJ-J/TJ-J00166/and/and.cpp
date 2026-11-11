#include<bits/stdc++.h>

using namespace std;
#define int long long
int b[200005];
int n,m;
int cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>b[i];
		if(b[i]>b[i-1]){
			cnt = b[i-1];
		}else{
			cnt = b[i];
		}
	}
	cout<<cnt;
	
	
	
	
	
	
	return 0;
}
