#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;cin>>a>>b>>c>>d;
	int a1=(a[0]-'0')*10+(a[1]-'0');
	int b1=(c[0]-'0')*10+(c[1]-'0');
	int a2=(b[0]-'0')*10+(b[1]-'0');
	int b2=(d[0]-'0')*10+(d[1]-'0');
	char a3=b[2],b3=d[2];
	cout<<(a1==b1)<<((a1==b1)&(a2==b2));
	if((min(a3,b3)>='D'||max(a3,b3)<='C')&&(a1==b1)&&(a2==b2)){
		cout<<1;
		if(abs(a3-b3)==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0<<0;
	}
}
