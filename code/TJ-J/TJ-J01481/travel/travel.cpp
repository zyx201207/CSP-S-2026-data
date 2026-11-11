#include <bits/stdc++.h>
using namespace std;
char gh[3]={'A','B','C'};
char sd[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool q=0,w=0,e=0,r=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		q=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&q==1){
		w=1;
	}
	if(w==1){
		for(int i=0;i<3;i++){
		if(s1[2]==gh[i]){
			for(int j=0;j<3;j++){
				if(s2[2]==gh[j]){
					e=1;
					if((i-j==1||j-i==1)){
						r=1;
					}
				}
			}
		}
	}
	for(int i=0;i<2;i++){
		if(s1[2]==sd[i]){
			e=1;
			for(int j=0;j<2;j++){
				if(s2[2]==sd[j]){
					e=1;
					if((i-j==1||j-i==1)){
						r=1;
					}
				}
			}
		}
	}
}
	cout<<q<<w<<e<<r;
	return 0;
} 
