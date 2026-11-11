#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if((a=='A' or a=='B' or a=='C') and (b=='A' or b=='B' or b=='C')) return 1;
	if((a=='D' or a=='F') and (b=='D' or b=='F')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1="",p2="";
//	p1=s1[0]+s1[1];
//	p2=s2[0]+s2[1];
//	cout<<p1<<' '<<p2<<' ';
	char t1=s1[2],t2=s2[2];
//	cout<<t1<<' '<<t2<<' ';
	if(c1==c2) cout<<'1';
	else cout<<'0';
	if(c1==c2 and p1==p2) cout<<'1';
	else cout<<'0';
	if(c1==c2 and p1==p2 and check(t1,t2)) cout<<'1';
	else cout<<'0';
	if(c1==c2 and p1==p2 and check(t1,t2) and (abs(t1-t2)==1 or(t1=='D' and t2=='F') or (t1=='F' and t2=='D'))) cout<<'1';
	else cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
