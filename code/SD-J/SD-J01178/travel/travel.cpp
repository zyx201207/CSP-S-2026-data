#include<bits/stdc++.h>
using namespace std;
char alp_bt[]={'A','B','C',' ','D','F'};
string c1,s1,c2,s2;
bool f[5];
int alp(char c){
	for(int i=0;i<3;i++) if(c==alp_bt[i]) return 1;
	return 2;
}
bool check1(char a,char b){
	if(alp(a)==alp(b)) return true;
	else return false;
}
bool check2(char a,char b){
	int n1,n2;
	for(int i=0;i<6;i++){
		if(a==alp_bt[i]) int n1=i;
		if(b==alp_bt[i]) int n2=i;
	}if(abs(n1-n2)==1) return true;
	else return false;
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	f[1]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	f[2]=1;
	char cc1=s1[2],cc2=s2[2];
	if(check1(cc1,cc2)==true){
	f[3]=1;
	if(check2(cc1,cc2)==true){
	f[4]=1;
	}
	}
	}
	}
	for(int i=1;i<=4;i++) cout<<f[i];
	return 0;
}
