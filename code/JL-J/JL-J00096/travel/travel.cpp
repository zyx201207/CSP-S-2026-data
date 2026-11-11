#include <cstdio>
#include <cmath>
int a1,b1,a2,b2,ans1,ans2,ans3,ans4;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1==a2){
		ans1=1;
		if(b1==b2){
			ans2=1;
			if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
				ans3=1;
				if(abs(c1-c2)==1||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
					ans4=1;
				}
			}
		}
	}
	printf("%d%d%d%d",ans1,ans2,ans3,ans4);
	return 0;
}
