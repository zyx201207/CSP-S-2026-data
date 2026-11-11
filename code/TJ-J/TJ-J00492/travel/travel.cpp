#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool m1[300];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b,c,d;m1['A']=m1['B']=m1['C']=1;
	char e,f;
	cin>>a;
	scanf("%lld%c",&b,&e);
	cin>>c;
	scanf("%lld%c",&d,&f);
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if(m1[e]==m1[f]){
				cout<<"1";
				if(m1[e]&&m1[f]){
					cout<<(abs(e-f)==1);
				}else{
					cout<<1;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
} 
