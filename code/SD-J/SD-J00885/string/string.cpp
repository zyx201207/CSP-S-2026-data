#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+10;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n == 1){
		cout<<0;
	}
	long long le = 0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		le+=x;
		char y;
		cin>>y;
		while(x--){
			a+=y;
		}
	}
	int ii = 0,jj = le-1;
	long long cnt = 0;
	while(ii<=jj){
		if(a[ii] != a[jj]){
			cnt++;
		}
		ii++;
		jj--;
	}
	cout<<cnt;
	return 0;
}
