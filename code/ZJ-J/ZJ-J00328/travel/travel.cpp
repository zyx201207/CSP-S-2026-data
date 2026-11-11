#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
string a,b,c,d;
signed main(){
	IOS
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int x=(a[0]-'0')*10+a[1]-'0',y=(c[0]-'0')*10+c[1]-'0';
	int pai1=(b[0]-'0')*10+b[1]-'0',pai2=(d[0]-'0')*10+d[1]-'0';
	if(x==y){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
				cout<<1;
				if(abs(b[2]-d[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}

	
	
	return 0;
}
