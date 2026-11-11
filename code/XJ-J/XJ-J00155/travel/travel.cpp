#include <bits/stdc++.h>
using namespace std;
int a,b;
string c1,c2,s1,s2;
int q,w,e,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2; 
	if(c1==c2){
		q=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			w=1;
			if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
				e=1;
				if(abs(s1[2]-s2[2])==1){
					r=1;
				}
			}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&(s1[2]!=s2[2])){
				e=1;
				r=1;
			}
		}
	} 
	cout<<q<<w<<e<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
