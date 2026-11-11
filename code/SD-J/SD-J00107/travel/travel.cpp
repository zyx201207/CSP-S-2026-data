#include<bits/stdc++.h>
using namespace std;
int ab[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a!=x){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]!=y[0]||b[1]!=y[1]){
		cout<<"000";
		return 0;
	} 
	cout<<"1";
	int e=int(b[2]-'A')+1,r=int(y[2]-'A')+1;
	if(e>3) ab[e+1]=1;
	else ab[e]=1;
	if(r>3)ab[r+1]=1;
	else ab[r]=1;
	if((ab[6]==1&&ab[5]==1)||(ab[6]!=1&&ab[5]!=1)){
		cout<<"1";
		if(ab[e+1]==1||ab[e-1]==1){
			cout<<"1";
		}
		else cout<<"0";
		return 0;
	}
	cout<<"00";
	return 0;
}
