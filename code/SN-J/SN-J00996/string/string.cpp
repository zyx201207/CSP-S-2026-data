#include <bits/stdc++.h>
using namespace std;
#define int long long
string x;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		string a1;
		cin>>a>>a1;
		sum+=a;
		for(int i=1;i<=a;i++){
			x+=a1;
		}
	}
	int r=sum-1;
	for(int i=0;i<sum/2;i++){
		if(x[i]!=x[r]) cnt++;
		r--;
	}
	cout<<cnt;
	return 0;
}
