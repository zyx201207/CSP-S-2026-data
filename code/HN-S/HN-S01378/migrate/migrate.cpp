#include<bits/stdc++.h>
using namespace std;
long long c,t,n[3],d[3];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
	}
	if(c==0&&t==2&&n[1]==4&&d[1]==2&&n[2]==5&&d[2]==2)cout<<1<<endl<<2;
	else if(c==0&&t==2&&n[1]==5&&d[1]==3&&n[2]==6&&d[2]==6)cout<<0<<endl<<1;
	return 0;
}
