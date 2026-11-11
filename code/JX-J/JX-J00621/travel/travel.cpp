#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1[1]==c3[1] && c1[0]==c3[0])cout<<1;
	else {
		for(int i=1;i<=4;i++)cout<<0;
		return 0;
	}
	if(c2[0]==c4[0] && c2[1]==c4[1])cout<<1;
	else {
		for(int i=2;i<=4;i++)cout<<0;
		return 0;
	}
	if(c2[2]>='A'&& c2[2]<='C'&&c4[2]>='A' && c4[2]<='C' && c2[2]!=c4[2])
	{
		cout<<1;
		k=1;
	}
	else{
		for(int i=3;i<=4;i++)cout<<0;
		return 0;
	}
	if(c2[2]>='D'&& c2[2]<='F'&&c4[2]>='D' && c4[2]<='F'&& c2[2]!=c4[2])cout<<1;
	else if(k==0){
		for(int i=3;i<=4;i++)cout<<0;
		return 0;
	}
	if(c2[2]==c4[2]+1||c2[2]==c4[2]-1)cout<<1;
	else cout<<0;
return 0;
}
