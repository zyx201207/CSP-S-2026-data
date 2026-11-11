#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1[0]==c_2[0] && c_1[1]==c_2[1]){
		cout<<1;
		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){
			cout<<1;
			if(s_1[2]<='C'&&s_2[2]<='C'){
				cout<<1;
				if(abs(int(s_1[2]-s_2[2]))==1){
					cout<<1<<'\n';
				}
				else{
					cout<<0<<'\n';
				}
			}
			else if(s_1[2]>='D'&&s_2[2]>='D'){
				cout<<1<<1<<'\n';
			}
			else{
				cout<<0<<0<<'\n';
			}
		}
		else{
			cout<<0<<0<<0<<'\n';
		}
	}
	else{
		cout<<0<<0<<0<<0<<'\n';
	}
	return 0;
} 
