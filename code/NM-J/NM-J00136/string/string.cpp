

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long x;
		char s;
		cin>>x>>s;
		cnt+=x;
	}
	cout<<cnt/2;
	return 0;
}
