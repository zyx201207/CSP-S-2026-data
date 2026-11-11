#include <bits/stdc++.h>
using namespace std;
int n,m,a=0,e,cinclock,coutclock;
long long ans=0;
string b,c,d;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string,in","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			b+=c;
		}
		b+=m;
	}
	int i,j;
	for(longlong i=0,j=m-1;i<=j;i++,j--){
		if(b[i]!=b[j]){
			ans++;
		}
}
	cout<<ans;
	return 0;
}
