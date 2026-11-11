#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	int w1=s1[2]-'A';
	int w2=s2[2]-'A';
	if(c1==c2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if((w1<3&&w2<3)||(w1>=3&&w2>=3)){
				cout<<"1";
				if(abs(w1-w2)==1){
					cout<<"1";
				}
				else cout<<"0"<<endl;
			}
			else cout<<"00"<<endl;
			}
		else cout<<"000"<<endl;
		}
	else cout<<"0000"<<endl;
	return 0;
}

