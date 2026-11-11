#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int a[N],b[N];
string s1,s2,t1,t2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['A']=1,a['B']=1,a['C']=1,a['D']=2,a['F']=2;
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<'1';
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			cout<<'1';
			if(a[s2[2]]==a[t2[2]]){
				cout<<1;
				if(s2[2]=='A'&&t2[2]=='C')    cout<<'0';
				else if(t2[2]=='A'&&s2[2]=='C')    cout<<'0';
				else    cout<<1;
			}else    cout<<"00";
		}else    cout<<"000";
	}else    cout<<"0000";
	return 0;
}//100
