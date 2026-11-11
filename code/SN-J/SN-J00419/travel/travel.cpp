#include<bits/stdc++.h>
using namespace std;

//CCF are handsome!
//Please give me more score!
//rp++!
//FULL MARK PLEASE!

string a,b;
string yzq_front1,yzq_front2,c1,c2;
char yzq_last1,yzq_last2;
int f[5005];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	yzq_front1=a.substr(0,2);
	yzq_last1=a[2];
	yzq_front2=b.substr(0,2);
	yzq_last2=b[2];
	if(yzq_last1=='F') yzq_last1='E';
	if(yzq_last2=='F') yzq_last2='E';
	f['A']=f['B']=f['C']=1;
	f['D']=f['E']=2;
	if(c1!=c2) cout<<"0000";
	else if(yzq_front1!=yzq_front2) cout<<"1000";
	else if(f[yzq_last1]!=f[yzq_last2]) cout<<"1100";
	else{
		if(abs(yzq_last1-yzq_last2)==1) cout<<"1111";
		else cout<<"1110";
	}
	return 0;
}
