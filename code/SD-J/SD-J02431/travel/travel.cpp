#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	
	if(a==c)
	{
		
		string e=b.substr(0,2),f=d.substr(0,2);
		if(e==f)
		{
			
			{
				char g1=b[2],g2=d[2];
				if(((g1=='A'||g1=='B'||g1=='C')&&(g2=='A'||g2=='B'||g2=='C'))||((g1=='D'||g1=='F')&&(g2=='D'||g2=='F'))){
					
					if((g1=='A'&&g2=='B')||(g1=='B'&&g2=='A')||(g1=='B'&&g2=='C')||(g1=='C'&&g2=='B')||(g1=='D'&&g2=='F')||(g1=='F'||g1=='D')) cout<<1111;
					else cout<<1110;
				}
				else cout<<"1100";
			}
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
