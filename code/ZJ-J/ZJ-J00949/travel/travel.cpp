#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
map<char,int>g,ff;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	g['A']=g['B']=g['C']=1,g['D']=g['F']=2;
	ff['A']=1,ff['B']=2,ff['C']=3,ff['D']=5,ff['F']=6;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(b[0]+b[1]!=d[0]+d[1]){
			cout<<"000";
		}
		else{
			cout<<1;
			if(g[b[2]]!=g[d[2]]){
				cout<<"00";
			}
			else{
				cout<<1;
				if(abs(ff[b[2]]-ff[d[2]])==1) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
