#include <bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int n1,m1,n2,m2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1>>c1>>s2>>c2;
	n1=10*(c1[0]-'0')+(c1[1]-'0');
	n2=10*(c2[0]-'0')+(c2[1]-'0');
	m1=c1[2]-'A'+1; m2=c2[2]-'A'+1;
	
	if(s1==s2){
		cout<<"1";
		if(n1==n2){
			cout<<"1";
			if((m1<=3 && m2<=3) || (m1>=4 && m2>=4)){
				cout<<"1";
				if(m1+1==m2 || m1-1==m2)
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
