#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(NULL);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if((s1[0]!=s2[0])||(s1[1]!=s2[1])) cout<<"000";
		else{
			cout<<"1";
			char c=s1[2],d=s2[2];
			if(c=='F') c='E';
			if(d=='F') d='E';
			if(!((c<'D'&&d<'D')||(c>'C'&&d>'C'))) cout<<"00";
			else{
				cout<<"1";
				if(abs(c-d)!=1) cout<<"0";
				else cout<<"1";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
