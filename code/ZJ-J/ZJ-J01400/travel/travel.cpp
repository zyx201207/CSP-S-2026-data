#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		int po1=s1[0]*10+s1[1]*1;
		int po2=s2[0]*10+s2[1]*1;
		if(po1!=po2) cout<<"000";
		else {
			cout<<"1";
			char ch1,ch2;
			ch1=s1[2];
			ch2=s2[2];
			if(ch1>='A' && ch1<='C' && ch2>='A' && ch2<='C') {
				cout<<"1";
				if((ch1=='A' && ch2=='C') || (ch2=='A' && ch1=='C'))cout<<"0";
				else cout<<1;
			}
			else if((ch1=='D' || ch1=='F') && (ch2=='D' || ch2=='F')) {
				cout<<"11";
			}
			else cout<<"00";
		}
	}	
	return 0;
}
