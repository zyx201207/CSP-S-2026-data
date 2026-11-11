#include<iostream>
using namespace std;

string c1,s1,c2,s2;
int rt[9];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=(s1[0]-'0')*10+(s1[1]-'0');
	int b=(s2[0]-'0')*10+(s2[1]-'0');	
	char x=s1[2];
	char y=s2[2];
	if(c1==c2){
		rt[1]=1;
		if(a==b){
			rt[2]=1;
			if(x=='F'&&y=='D'||x=='D'&&y=='F'||x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'||x=='A'&&y=='C'||x=='C'&&y=='A'){
				rt[3]=1;
				if(x=='F'&&y=='D'||x=='D'&&y=='F'||x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'){
					rt[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<rt[i];
	}
	return 0;
}
