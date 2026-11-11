#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int a1,a2,b1,b2;
bool t1,t2,t3,t4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a1=a1*10+(c1[i]-'0');
		a2=a2*10+(c2[i]-'0');
		b1=b1*10+(s1[i]-'0');
		b2=b2*10+(s2[i]-'0');
	}
	char c1=s1[2],c2=s2[2];
	if(c1=='F') c1='E';
	if(c2=='F') c2='E';
	if(a1==a2) {
		t1=true;
		if(b1==b2){
			t2=true;
			if(c1>='D'&&c1<='E'&&c2>='D'&&c2<='E'){
				t3=t4=true;
			}
			if(c1>='A'&&c1<='c'&&c2>='A'&&c2<='C'){
				t3=true;
				if(c1+1==c2||c2+1==c1){
					t4=true;
				}
			}
		}
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
} 
