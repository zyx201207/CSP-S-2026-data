#include<bits/stdc++.h>
using namespace std;
int m,n;
char a[3],b[3];
char k;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	cin>>m;
	cin>>b[0]>>b[1]>>b[2];
	if(n==m){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			if((a[2]-'A'<=2)==(b[2]-'A'<=2)){
				cout<<1;
				if(abs(a[2]-b[2])==1) cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
