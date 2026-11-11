#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a,b;
	string s1,s2;
	cin>>a>>s1;
	cin>>b>>s2;
	if(a!=b){
		cout<<"0000"<<endl;
		return 0;
	}
	if(a==b){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s1[2]>'C')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
 } 
 //Trick||Treat!
 //CCF has no egg!
 //RP++
 //Coin Cellecting Foundation
