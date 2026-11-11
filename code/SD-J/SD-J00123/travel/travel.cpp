#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);


	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string c1,c2;
	int num1,num2;
	char r1,r2;
	cin>>c1>>num1>>r1>>c2>>num2>>r2;
	
	int ans1=0,ans2=0,ans3=0,ans4=0;
	
	
	
	if(c1==c2)ans1=1;
	if(ans1==1&&num1==num2)ans2=1;
	if(ans2==1&&(r1<='C'&&r2<='C'||r1>='D'&&r2>='D'))ans3=1;
	if(ans3==1&&abs(r1-r2)==1)ans4=1;
	
	cout<<ans1<<ans2<<ans3<<ans4;
	
	return 0;
}
