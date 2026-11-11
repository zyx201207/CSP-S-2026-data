#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) printf("0000\n");//条件一 
	else{
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){//条件二
				printf("1000\n");
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'&&2){//条件三 
			if(char(s1[2]-1)==s2[2]||char(s1[2]+1)==s2[2]) printf("1111\n");//条件四 
		    else printf("1110\n");  	    
		}else{
		    printf("1100\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
