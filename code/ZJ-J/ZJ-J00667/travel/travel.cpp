#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
string c1,s1,c2,s2;
char a[4];
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]='1';
	}else a[0]='0';
	if(a[0]=='1'){
		bool p=0;
		char q1[2]={s1[0],s1[1]},q2[2]={s2[0],s2[1]};
		for(int i=0;i<2;i++){
			if(q1[i]!=q2[i]){
				a[1]='0';
				p=1;
				break;
			}
		}
		if(!p) a[1]='1';
	}else a[1]='0';
	if(a[1]=='1'){
		char w1=s1[2],w2=s2[2];
		if((w1<='C'&&w2<='C')||(w1>='D'&&w2>='D')){
			a[2]='1';
		}else a[2]='0'; 
	}else a[2]='0';
	if(a[2]=='1'){
		char w1=s1[2],w2=s2[2];
		if((w1=='D'&&w2=='C')||(w1=='C'&&w2=='D')) a[3]='0';
		if((w1=='A'&&w2=='B')||(w1=='B'&&w2=='A')||(w1=='B'&&w2=='C')||(w1=='C'&&w2=='B')||(w1=='D'&&w2=='F')||(w1=='F'&&w2=='D')){
			a[3]='1';
		}else a[3]='0';
	}else a[3]='0';
	cout<<a;
	return 0;
}
