#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;
bool sf[4];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		sf[0]=1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			sf[1]=1;
			char a=a2[2],b=b2[2];
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F')){
				sf[2]=1;
				if(abs(a-b)==1)
					sf[3]=1;
			}
		}
	}
	for(int i = 0;i<4;i++)
		cout<<sf[i];
	
	return 0;
}