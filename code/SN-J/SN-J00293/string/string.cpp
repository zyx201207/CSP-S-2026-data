#include<bits/stdc++.h>
using namespace std;
struct string{
	int shu;
	char zhong;
}a[200001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int b;
	int c=0;
	int d=0;
	int e,f=1;
	scanf("%d",&b);
	for(int i=1;i<=b;i++){
		scanf("%d %c",&a[i].shu,&a[i].zhong);
		//printf("%d%c",a[i].shu,a[i].zhong); 
		c=c+a[i].shu;
	}
	c=c/2;
	for(int i=1;i<=c;i++){
		//printf("1 ");
		if(a[e].zhong==a[b+1-f].zhong&&a[e].shu>0&&a[b+1-f].shu>0){
			a[e].shu--;
			a[b+1-f].shu--;
			//printf("%d %d \n",a[e].shu,a[b+f-1].shu);
		}
		if(a[e].shu<=0) {
			e++;
		}
		if(a[b+1-f].shu<=0){
			f++;
		}
		if(a[e].zhong!=a[b+1-f].zhong&&a[e].shu>0&&a[b+1-f].shu>0){
			d++;
			a[e].shu--;
			a[b+1-f].shu--;
			//printf("%d %d\n ",a[e].shu,a[b+1-f].shu);
			//printf("%d\n",d);
		}
	}
	printf("%d",d);	
	return 0;
 }
