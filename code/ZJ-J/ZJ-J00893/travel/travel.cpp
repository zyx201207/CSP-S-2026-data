#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int vis[6]={0,0,0,1,2,1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c){
		if (b[0]==d[0] && b[1]==d[1]){
			int x=b[2]-'A', y=d[2]-'A';
			if (vis[x]==vis[y]){
				if (abs(x-y)==1 || (x==3 && y==5) || (x==5 && y==3)) cout<<"1111";
				else cout<<"1110";
			} else {
				cout<<"1100";
			}
		} else {
			cout<<"1000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}