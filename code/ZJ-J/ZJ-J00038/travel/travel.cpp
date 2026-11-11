#include<bits/stdc++.h>
using namespace std;
char a[110],b[110],c[110],d[110];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			if(b[2]=='A'&&d[2]=='B')
			    printf("11");
			else if(b[2]=='A'&&d[2]=='C')
			    printf("10");
			else if(b[2]=='A'&&d[2]=='D')
			    printf("00");
			else if(b[2]=='A'&&d[2]=='F')
			    printf("00");
			else if(b[2]=='B'&&d[2]=='A')
			    printf("11");
			else if(b[2]=='B'&&d[2]=='C')
			    printf("11");
			else if(b[2]=='B'&&d[2]=='D')
			    printf("00");
			else if(b[2]=='B'&&d[2]=='F')
			    printf("11");
			else if(b[2]=='C'&&d[2]=='A')
			    printf("10");
			else if(b[2]=='C'&&d[2]=='B')
			    printf("11");
			else if(b[2]=='C'&&d[2]=='D')
			    printf("00");
			else if(b[2]=='C'&&d[2]=='F')
			    printf("00");
			else if(b[2]=='D'&&d[2]=='A')
			    printf("00");
			else if(b[2]=='D'&&d[2]=='B')
			    printf("00");
			else if(b[2]=='D'&&d[2]=='C')
			    printf("00");
			else if(b[2]=='D'&&d[2]=='F')
			    printf("11");
			else if(b[2]=='F'&&d[2]=='A')
			    printf("00");
			else if(b[2]=='F'&&d[2]=='B')
			    printf("00");
			else if(b[2]=='F'&&d[2]=='C')
			    printf("00");
			else if(b[2]=='F'&&d[2]=='D')
			    printf("11");
		}else
			printf("000");
	}else
	    printf("0000");
	return 0;
}
