#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
char d1,d2;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<'1';
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		if(a!=b){
			cout<<"000";
			return 0;
		}else{
			cout<<'1';
			d1=s1[2];
			d2=s2[2];
			if(d1=='A'||d1=='B'||d1=='C'){
			    if(d2=='A'||d2=='B'||d2=='C'){
					cout<<'1';
					if(d2-d1==1||d1-d2==1){
						cout<<'1';
						return 0;
					}else{
						cout<<'0';
						return 0;
					}
			    }else{
					cout<<"00";
					return 0;
				}
			}else{
				if(d2=='D'||d2=='E'){
					cout<<"11";
					return 0;
				}else{
					cout<<"00";
					return 0;
				}
			}
		}
	}
	return 0;
}
