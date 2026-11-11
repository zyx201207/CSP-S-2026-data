#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200000+10];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	string w;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		for(int j=1;j<=a[i];j++){
			w+=c;
		}
	
	}
	for(int i=0;i<(w.size()/2)+1;i++){
		if(w[i]!=w[w.size()-1-i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
