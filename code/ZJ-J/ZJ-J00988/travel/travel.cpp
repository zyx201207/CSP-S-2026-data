#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		ll k1=(s1[0]-'0')*10+(s1[1]-'0');
		ll k2=(s2[0]-'0')*10+(s2[1]-'0');
		if(k1!=k2) cout<<"000";
		else{
			cout<<1;
			ll t1=s1[2]-'A',t2=s2[2]-'A';
			if(t1+t2==7) cout<<11;
			else if(t1<3 && t2<3){
				if(std::abs(t1-t2)==1) cout<<11;
				else cout<<10;
			}
			else cout<<"00";
		}
	}
	return 0;
}
