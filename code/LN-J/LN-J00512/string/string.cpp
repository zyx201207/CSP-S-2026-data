#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],n,ans;
char b[200010];
string P;
vector<pair<int,int> >vec;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			P=P+b[i];
		}
	}
	for(int i=0;i<P.length()/2-1;i++){
		if(P[i]!=P[P.length()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
