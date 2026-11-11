//RP+=INF
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
	}
	else{
		cout<<1;
		int a=s1[0]-'0',b=s1[1]-'0';
		char c=s1[2];
		int aa=s2[0]-'0',bb=s2[1]-'0';
		char cc=s2[2];
		if(a!=aa||b!=bb){
			cout<<"000\n";
		}
		else{
			cout<<1;
			if((c=='F'||c=='D')&&(cc=='F'||cc=='D')){
				cout<<"11\n";
			}
			else if((c=='A'||c=='B'||c=='C')&&(cc=='A'||cc=='B'||cc=='C')){
				cout<<1;
				if(abs(int(c-cc))==1){
					cout<<1<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
			else{
				cout<<"00\n";
			}
		}
	}
	return 0;
}