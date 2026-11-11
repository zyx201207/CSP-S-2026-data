#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2) ans+='1';
	else ans+='0';
	if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]&&zw1!=zw2) ans+='1';
	else ans+='0';
	if(ans[1]=='1'&&zw1[2]>='A'&&zw1[2]<='C'&&zw2[2]>='A'&&zw2[2]<='C'&&zw1!=zw2) ans+='1';
	else if(ans[1]=='1'&&zw1[2]>='D'&&zw1[2]<='F'&&zw2[2]>='D'&&zw2[2]<='F'&&zw1!=zw2) ans+='1';
	else ans+='0';
	if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]&&(zw1[2]+1==zw2[2]||zw1[2]-1==zw2[2])&&zw1!=zw2) ans+='1';
	else if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]&&(zw1[2]=='C'&&zw2[2]=='D'||zw1[2]=='D'&&zw2[2]=='C')&&zw1!=zw2) ans[3]='0';
	else if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]&&((zw1[2]=='D'&&zw2[2]=='F')||(zw1[2]=='D'&&zw2[2]=='F'))&&zw1!=zw2) ans+='1'; 
	else ans+='0';
	cout<<ans;
	return 0;
}
