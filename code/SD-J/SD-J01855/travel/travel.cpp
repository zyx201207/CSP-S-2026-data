#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt,cnt2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
				cout<<"1";
				cnt=b[2]-'A';
				cnt2=d[2]-'A';
				if(cnt>cnt2)ans=cnt-cnt2;
				else ans=cnt2-cnt;
				if(ans>1){
					cout<<"0";
				}
				else cout<<"1";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
