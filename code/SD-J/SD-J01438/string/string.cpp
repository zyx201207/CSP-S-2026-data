#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0,l;
vector<char> a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n;
	l+=n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		l+=(x-1);
		while(x--){
			a.push_back(y);
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[l-i-1])sum++;
	}
	cout<<sum<<endl;
	return 0;
}
