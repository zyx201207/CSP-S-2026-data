#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=1e5+10;
int n,m;
string jjhs1,jjhs2,jjhs3,jjhs4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>jjhs1>>jjhs2>>jjhs3>>jjhs4;
	if(jjhs1==jjhs3){
		cout<<1;
		if(jjhs2[0]==jjhs4[0] && jjhs2[1]==jjhs4[1]){
			cout<<1;
			bool flag=0;
			char jjhch1=jjhs2[2],jjhch2=jjhs4[2];
			if(jjhch1=='F') flag=(jjhch2=='D');
			if(jjhch1=='D') flag=(jjhch2=='F');
			if(jjhch1=='A') flag=((jjhch2=='B')||(jjhch2=='C'));
			if(jjhch1=='B') flag=((jjhch2=='A')||(jjhch2=='C'));
			if(jjhch1=='C') flag=((jjhch2=='B')||(jjhch2=='A'));
			if(flag){
				bool flag1=0;
				cout<<1;
				if(jjhch1=='F') flag1=(jjhch2=='D');
				if(jjhch1=='D') flag1=(jjhch2=='F');
				if(jjhch1=='A') flag1=((jjhch2=='B')||(jjhch2=='C'));
				if(jjhch1=='B') flag1=(jjhch2=='A');
				if(jjhch1=='C') flag1=(jjhch2=='B');
				if(flag1) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
