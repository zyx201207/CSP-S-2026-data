#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p1,p2,p3,p4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		p1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			p2=1;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(s1[2]=='A'+i&&s2[2]=='A'+j){
						if(abs(s1[2]-s2[2])==1){
							if(!(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C')){
								p4=1;
							}
						}
						p3=1;
					}
				}
			}
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					if(s1[2]=='D'+i&&s2[2]=='D'+j){
						if(abs(s1[2]-s2[2])==1){
							if(!(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C')){
								p4=1;
							}
						}
						
						p3=1;
					}
				}
			}
			
			
		}
	}
	cout<<p1<<p2<<p3<<p4;
	
	return 0;
}
