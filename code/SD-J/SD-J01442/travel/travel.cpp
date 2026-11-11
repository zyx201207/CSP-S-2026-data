#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e3+5;
string s,s1,r,r1;
bool a,b,c,d,vis[20][20];
int number(string x){
	int n=0,len=x.size(),start=0;
	for(int i=0;i<len;i++){
		n=n*10+x[i]-'0';
	}
	return n;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>r>>r1;
	if(s==r){
		cout<<"1";
		string tmp1=s1.substr(0,2);
		string tmp2=r1.substr(0,2);
		if(tmp1==tmp2){
			cout<<"1";
			char x1=s1[2],x2=r1[2];
			int che1,che2;
			if(x1>='A'&&x1<='C')che1=1;
			else che1=0;
			if(x2>='A'&&x2<='C')che2=1;
			else che2=0;
			if(che1==che2){
				cout<<"1";
				int l1,l2,l3,l4;
				l1=number(tmp1);
				l2=number(tmp2);
				l3=s1[2]-'A'+1;
				l4=r1[2]-'A'+1;
				vis[l1][l3]=1;
				vis[l2][l4]=1;
				if(vis[l1-1][l3]||vis[l1+1][l3]||vis[l1][l3-1]||vis[l1][l3+1]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

