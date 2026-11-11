#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,w,t;
	cin>>c>>n>>m>>d;
	int a[m];
	for(int i=0;i<=n;i++){
		c+=i;
		for(int j=0;j<=m;j++){
			w+=j;
		}
	}
	cout<<t<<endl;
	return 0;
}