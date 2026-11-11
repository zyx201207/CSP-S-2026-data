#include<bits/stdc++.h>
#define ll long long
#define F(l,r,i) for(int i=l;i<=r;i++)
#define Fa(l,r,i) for(int i=r;i>=l;i--)
using namespace std;
string ca,sa,cb,sb;
signed main(){
	//freopen("travel2.in","r",stdin);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	string paia=sa.substr(0,2),paib=sb.substr(0,2);
	string weia=sa.substr(2,1),weib=sb.substr(2,1);
	//cout<<paia<<" "<<paib<<endl<<weia<<" "<<weib<<endl;
	if(ca==cb){
		cout<<1;
		if(paia==paib){
			cout<<1;
			if(weia=="D"&&weib=="F") cout<<11;
			else if(weia=="A"&&weib=="B") cout<<11;
			else if(weia=="A"&&weib=="C") cout<<10;
			else if(weia=="B"&&weib=="C") cout<<11;
			else if(weib=="D"&&weia=="F") cout<<11;
			else if(weib=="A"&&weia=="B") cout<<11;
			else if(weib=="A"&&weia=="C") cout<<10;
			else if(weib=="B"&&weia=="C") cout<<11;
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
