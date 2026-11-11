 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	string c1,s1,c2,s2;
 	cin>>c1>>s1>>c2>>s2;
 	if(c1==c2){
 		printf("1");
 		if(s1[0]==s2[0]&&s1[1]==s2[1]){
 			printf("1");
 			int w1,w2;
 			if(s1[2]<='C')w1=1;
 			else w1=2;
 			if(s2[2]<='C')w2=1;
 			else w2=2;
 			cout<<" "<<w1<<" "<<w2<<" "; 
 			if(w1==w2){
 				printf("1");
 				if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')printf("0");
 				else printf("1");
 			}
 			else printf("00");
		}
 		else printf("000");
	}
 	else printf("0000");
 	return 0;
 }
