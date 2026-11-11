#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	printf("%d",1);
	    if(s1[0]+s1[1]==s2[0]+s2[1]){
	    	printf("%d",1);
		    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		    	n=1;
			}
			if(s1[2]=='D' || s1[2]=='F'){
		    	n=2;
			}
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
		    	m=1;
			}
			if(s2[2]=='D' || s2[2]=='F'){
		    	m=2;
			}
			if(n==m){
				printf("%d",1);
				if(m==2 || abs(s1[2]-s2[2])==1){
					printf("%d",1);
				}
				else{
					printf("%d",0);
				}
			}
			else{
				printf("%d%d",0,0);
			}
		}
		else{
	    	printf("%d%d%d",0,0,0);
		}
	}
	else{
		printf("%d%d%d%d",0,0,0,0);
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
