#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2,ans="";
	cin>>c_1>>s_1>>c_2>>s_2;
	char ss=s_1[0],sss=s_1[1],ssss=s_2[0],sssss=s_2[1];
	bool f_1=0,f_2=0,f_3=0;
	if(c_1==c_2)ans+='1',f_1=1;
	else ans+='0';
	if(ss==ssss && sss==sssss && f_1)ans+='1',f_2=1;
	else ans+='0';
	char xs=s_1[2],xc=s_2[2];
	if(f_2 && ((xs=='F'||xs=='D' && xc=='D' || xc=='F')||(xs=='A' || xs=='B'||xs=='C' &&xc=='A' || xc=='B'||xc=='C')))ans+='1',f_3=1;
	else ans+='0';
	if(xs>xc)swap(xs,xc);
	if(f_3 && (xs=='A' && xc=='B') || (xs=='B' && xc=='C')||(xs=='D' && xc=='F'))ans+='1';
	else ans+='0';
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
