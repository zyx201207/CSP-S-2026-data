#include<bits/stdc++.h> 
using namespace std;
bool a,b,c,d;
int a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			a1+=1;
		}
	}
	if(a1==2)a=1;
	if(a){
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				b1+=1;
			}
		}
		if(b1==2)b=1;
		if(b){
			char s_1,s_2;
			s_1=s1[2];
			s_2=s2[2];
			if(s_1=='A'&&s_2=='B'||s_1=='B'&&s_2=='A'||s_1=='B'&&s_2=='C'||s_1=='C'&&s_2=='B'||s_1=='D'&&s_2=='F'||s_1=='F'&&s_2=='D'){
				c=1;
				d=1;
			}
			if(s_1=='A'&&s_2=='C'||s_1=='C'&&s_2=='A'){
				d=0;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
