#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd(string k1,string k2){
	if(k1.size()!=k2.size())return false;
	for(int i=0;i<k1.size();i++){
		if(k1[i]!=k2[i])return false;
	}
	return true;
}
bool pd2(string k1,string k2){
	if(k1.size()!=k2.size())return false;
	for(int i=0;i<k1.size()-1;i++){
		if(k1[i]!=k2[i])return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);//IMPORTANT
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(pd(c1,c2)){
		printf("1");
		if(pd2(s1,s2)){
			printf("1");
			if((s1[2]=='A' and (s2[2]=='B' or s2[2]=='C')) or (s1[2]=='B' and (s2[2]=='A' or s2[2]=='C')) or (s1[2]=='C' and (s2[2]=='B' or s2[2]=='A')) or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D')){
				printf("1");
				if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='C' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D')){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else {
		printf("0000");
	}
	return 0;
}