#include<bits/stdc++.h>
using namespace std;
	bool STR1(string s1,string s2){
		string c="",d="";
		for(int i=0;i<=1;i++){
			c[i]=s1[i];
			d[i]=s2[i];
		}
		return c==d;
	}
	bool STR2(string s1,string s2){
		char c=s1[2],d=s2[2];
		if((c>'C'&&d>'C')||(c<'C'&&d<'C')){
			return true;	
		}
		else{
			return false;
		}
	}
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		printf("%d",1);
		if(STR1(s1,s2)){
			printf("%d",1);
			if(STR2(s1,s2)){
				printf("%d",1);
			}
			else{
				printf("%d",0);
			}
		}
		else{
			printf("%d",0);
			printf("%d",0);
		}
		if(abs(s1[2]-s2[2])<=1){
			printf("%d",1);
		}
		else{
			printf("%d",0);
		}
	}
	else{
		printf("%d",0);
		printf("%d",0);
		printf("%d",0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
