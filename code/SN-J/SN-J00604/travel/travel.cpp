#include<bits/stdc++.h>
#define LL long long;
using namespace std;
char sit[3]={'A','B','C'};
char sit2[2]={'D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char p1,p2,p3,p4,p5,p6;
	p1=s1[0];
	p2=s2[0];
	p3=s1[1];
	p4=s2[1];
	p5=s1[2];
	p6=s2[2];
	
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&p1==p2&&p3==p4){
		cout<<1;
	}else{
		cout<<0;
	}
	
	bool temp=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(p5==sit[i]&&p6==sit[j]){
				temp=1;
			}
		}
	}	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(p5==sit2[i]&&p6==sit2[j]){
				temp=1;
			}
		}
	}
	
	if(c1==c2&&p1==p2&&p3==p4&&temp){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&p1==p2&&p3==p4&&temp&&abs(p5-p6)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
/*
:)
*/
