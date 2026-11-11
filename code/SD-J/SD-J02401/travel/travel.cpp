#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int p1,p2;
		p1=(s1[0]-'0'*10)+(s1[1]-'0');
		p2=(s2[0]-'0'*10)+(s2[1]-'0');
		if(p1==p2){
			char c1=s1[2],c2=s2[2];
			if(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))){
			if(((c1=='A'||c1=='C')&&c2=='B')||((c2=='A'||c2=='C')&&c1=='B')||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))){
				cout<<"1111";
			}
			else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
