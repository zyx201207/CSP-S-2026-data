#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2,t1,t2;
bool vis=0,vis1=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=1;i>=0;i--){
			t1+=s1[i];
		}
		for(int i=1;i>=0;i--){
			t2+=s2[i];
		}
		int h1=s1[2]-'A'+1;
		int h2=s2[2]-'A'+1;
		bool flag=0;
		if(t1==t2){
			cout<<1;
			if(h1==1){
				if(h2==2||h2==3){
					cout<<1;
					flag=1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(h1==2){
				if(h2==1||h2==3){
					cout<<1;
					flag=1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(h1==3){
				if(h2==1||h2==2){
					cout<<1;
					flag=1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(h1==4){
				if(h2==5){
					cout<<1;
					flag=1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(h1==5){
				if(h2==4){
					cout<<1;
					flag=1;
				}
				else
				{
					cout<<0;
				}
			}
		}
		else
		{
			cout<<"00";
		}
		if(flag==1){
			if((h1==3&&h2==1)||(h1==1&&h2==3)){
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
