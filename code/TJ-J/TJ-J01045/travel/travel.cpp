// 02 01A 02 01B
// 0123456789012
//A 65  B 66  C 67  D 68  E 69
#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
string m,n,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>n>>x>>y;
	if(m==x);
	else{cout<<"0000";return 0;}
	
	if(n[0]==y[0]&&n[1]==y[1]);
	else{cout<<"1000";return 0;}
	
	if(n[2]-y[2]<=2&&n[2]-y[2]>=-2){
		if(n[2]+y[2]>=137||n[2]+y[2]<=133);
			else{cout<<"1100";return 0;}
	}
	else{cout<<"1100";return 0;}
	
	if(n[2]-y[2]<=1&&n[2]-y[2]>=-1)cout<<"1111";
	else if(n[2]=='D'&&y[2]=='F')cout<<"1111";
	else if(n[2]=='F'&&y[2]=='D')cout<<"1111";
	else cout<<"1110";
	return 0;
} 
