#include<bits/stdc++.h> 
using namespace std;
string w,r;
int q,e;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r;
	if(q==e){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(w[0]==r[0]&&w[1]==r[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((w[2]=='A'||'B'||'C')&&(r[2]=='A'||'B'||'C'))//3
	{
		cout<<"1";
	}
	else if((w[2]=='D'||'E')&&(r[2]=='D'||'E')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(w[2]-1==r[2]){
		cout<<"1";
		return 0;
	}
	else if(w[2]+1==r[2]){
		cout<<"1";
		return 0;
	}
	else{
		cout<<"0";
	}
	return 0;
}
