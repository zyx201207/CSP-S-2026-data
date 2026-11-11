#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int N=1e6+10;
map<int,char>m;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int chang=1;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=chang;j<=chang+a;j++){
			m[i]=b;	
		}
		chang+=a;
	}
	int da=0;
	for(int i=1;i<=chang/2;i++){
		if(m[i]!=m[chang-i])da++;
	}
	cout<<da;
	return 0;
}


