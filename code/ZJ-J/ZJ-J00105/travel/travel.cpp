#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s1,s2,s3,s4;
bool se[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		se[0]=1;
		if(s2[0]+s2[1]==s4[0]+s4[1]){
			se[1]=1;
			int i=0,j=0;
			if(s2[2]>='A'&&s2[2]<='C') i=1;
			else if(s2[2]=='D'||s2[2]=='F') i=2;
			if(s4[2]>='A'&&s4[2]<='C') j=1;
			else if(s4[2]=='D'||s4[2]=='F') j=2;
			if(i==j){
				se[2]=1;
				int p=s2[2]-'A';
				int q=s4[2]-'A';
				if(p==5) p=4;
				if(q==5) p=4;
				if(abs(p-q)==1&&p+q!=5) se[3]=1;
			}
		}
	}
	cout<<se[0]<<se[1]<<se[2]<<se[3];
	return 0;
} 
