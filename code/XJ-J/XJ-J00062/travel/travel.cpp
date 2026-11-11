#include<bits/stdc++.h>
using namespace std;
int a,s,q,w;
string d,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>d>>s>>f;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')
		q=1;
	else
		q=0;
		
	if(f[2]=='A'||f[2]=='B'||f[2]=='C')
		w=1;
	else
		w=0;
		
	if(a==s){
		cout<<1;
		if(d[0]==f[0]&&d[1]==f[1]){
			cout<<1;
			if(q==w){
				cout<<1;
				if(int(d[2])+1==int(f[2])||int(d[2])-1==int(f[2])){
					cout<<1;
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
