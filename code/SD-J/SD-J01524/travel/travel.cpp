#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ache,ay,bche,by;
	cin>>ache>>ay>>bche>>by;
	if(ache!=bche){
		cout<<"0000";
		return 0;
	} 
	if(ay[0]!=by[0]||ay[1]!=by[1]){
		cout<<"1000";
		return 0;
	}
	if((ay[2]<='C'&&by[2]>='D')||(ay[2]>='D'&&by[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if(abs(ay[2]-by[2])!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
