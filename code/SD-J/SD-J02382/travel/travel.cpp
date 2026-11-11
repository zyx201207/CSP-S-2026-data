#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int xiang,pai,ce,lin;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		xiang=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			pai=1;
	 	
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
				ce=1; lin=1;
			}
			if(s1[2]<='C'&&s2[2]<='C'){
				ce=1;
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
					lin=1;
			}
		}
	}
	else{
		xiang=0; pai=0; ce=0;lin=0;
	}
	cout<<xiang<<pai<<ce<<lin;
	return 0;
}
