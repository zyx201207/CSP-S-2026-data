#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
int qwe[10001];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	qwe['A']=1;qwe['B']=1;qwe['C']=1;qwe['D']=2;qwe['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<1;
			if(qwe[s1[2]]==qwe[s2[2]]){
				cout<<1;
				if(s2[2]=='B'||qwe[s1[2]]==2||s1[2]=='B'){
					cout<<1<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}
