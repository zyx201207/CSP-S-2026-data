#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	string ac,bc;
	cin>>a; 
	cin>>ac;
	cin>>b;
	cin>>bc;
	
	if(a==b)
	{
		cout<<1;
		int az=(ac[0]-'0')*10+ac[1]-'0';
		int bz=(bc[0]-'0')*10+bc[1]-'0';
		int aa=ac[2]-'A',bb=bc[2]-'A';
		if(az==bz)
		{
			cout<<1;
			if(aa-bb==1||aa-bb==-1)
			{
				cout<<1;
				cout<<int(!((aa==2&&bb==3)||(bb==2&&aa==3)));
			}
			else
			cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

