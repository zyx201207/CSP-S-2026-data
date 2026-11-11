#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,k,k1;
	cin>>s>>s1>>k>>k1;
	if (s!=k){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		ll _s=(s1[0]-'0')*10+(s1[1]-'0');
		ll _k=(k1[0]-'0')*10+(k1[1]-'0');
		if (_s!=_k){
			cout<<"000";
		}else{
			cout<<1;
			ll l=s1[2]-'A',r=k1[2]-'A';
//			cout<<'\n'<<l<<'\n'<<r<<'\n';
			if (l==5)l--;
			if(r==5)r--;
			if (l>r)swap(l,r);
			
			if (l==0&&r==1||l==1&&r==2||l==0&r==2||l==3&r==4){
				cout<<1;
				if (r-l==1)cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
