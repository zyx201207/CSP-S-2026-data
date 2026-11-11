#include<bits/stdc++.h>
using namespace std;
int s=0,t1,t2;
char a[3],b[3],c[3],d[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
		
	}
	for(int i=0;i<2;i++){
		cin>>c[i];
		
	}
	for(int i=0;i<3;i++){
		cin>>d[i];
		
	}
	
	
	if(a[0]==c[0]&&a[1]==c[1]) printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(b[0]==d[0]&&d[1]==b[1]){
		printf("1");s=1;
	}
	else printf("0");
	if(s==1){
		if(b[2]>='A'&&b[2]<='C'){
			if(d[2]>='A'&&d[2]<='C'){
				printf("1");
				s=2;
			}
			else printf("0");
		}	
		else if(d[2]>='D'&&d[2]<='E'){
			if(b[2]>='D'&&b[2]<='E'){
				printf("1");
				s=2;
			}
			else printf("0");
		}
		else printf("0");
	}
	else printf("0");
	if(s==2){
		t1=d[2]-'a';
		t2=b[2]-'a';
		if(t1-t2==1||t2-t1==1) printf("1");
		else printf("0");
	}
	else printf("0");
	return 0;
}