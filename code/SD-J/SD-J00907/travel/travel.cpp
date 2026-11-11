#include <bits/stdc++.h>
#define CHECK_SIZE(x) cout<<#x<<": "<<sizeof(x)%1024<<"B "<<sizeof(x)%(1024*1024)/1024<<"KB "<<sizeof(x)/1024/1024<<"MB\n"
using namespace std;
bool at_up[512];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	CHECK_SIZE(at_up);
	
	at_up['D']=
	at_up['F']=true;
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool flag=true;
	flag&=(c1==c2);
	cout<<flag;
	flag&=(s1[0]==s2[0] && s1[1]==s2[1]);
	cout<<flag;
	flag&=(at_up[s1[2]]==at_up[s2[2]]);
	cout<<flag;
	flag&=(abs(s1[2]-s2[2])==1);
	cout<<flag;
	
	return 0;
} 
