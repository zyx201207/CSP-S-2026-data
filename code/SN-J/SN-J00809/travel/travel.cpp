//王子畅 西安市含光中学 SN-J00809 
#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char x[5],y[5],a3,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a1);
	cin>>x;
	scanf("%d",&b1);
	cin>>y;
	a2=(x[0]-'0')*10+(x[1]-'0');
	b2=(y[0]-'0')*10+(y[1]-'0');
	a3=x[2];
	b3=y[2];
	if(a1==b1){
		if(a2==b2){
			if(a3=='A'&&b3=='B'||a3=='A'&&b3=='C'||a3=='B'&&b3=='A'||a3=='B'&&b3=='C'||a3=='C'&&b3=='A'||a3=='C'&&b3=='B'||a3=='D'&&b3=='E'||a3=='E'&&b3=='D'){
				if(a3=='A'&&b3=='B'||a3=='B'&&b3=='A'||a3=='B'&&b3=='C'||a3=='C'&&b3=='B'||a3=='D'&&b3=='E'||a3=='E'&&b3=='D'){
					printf("1111");
				}else{
					printf("1110");
				}
			}else{
				printf("1100");
			}
		}else{
			printf("1000");
		}
	}else{
		printf("0000");
	}
	return 0;
}

