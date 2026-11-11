#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<char,char>,int>p={
{{'A','B'},2},{{'A','C'},1},
{{'B','A'},2},{{'B','C'},2},
{{'C','A'},1},{{'C','B'},2},
{{'D','F'},2},{{'F','D'},2},
};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string x,y;
	cin>>n>>x>>m>>y;
	if(n==m){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if(p[{x[2],y[2]}]){
				cout<<1;
				if(p[{x[2],y[2]}]-1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	cout<<endl;
	return 0;
}