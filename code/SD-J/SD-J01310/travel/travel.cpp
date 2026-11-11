#include<bits/stdc++.h>
using namespace std;
struct ss{
	int id;
	char seat;
}s1[1];
struct s{
	int id;
	char seat;
}s2[1];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0000";
	return 0;
}
