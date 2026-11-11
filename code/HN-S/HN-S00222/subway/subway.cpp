#include<bits/stdc++.h>
using namespace std;
long long a1[500010],a2[510][510],a3[500510],a5[510],a6[510];
struct t1{
	long long a,b,c;
}a4[500010];
long long s1(){
	long long i=0,j=1;
	char k=getchar();
	while(k<'0'||k>'9'){
		if(k=='-'){
			j=-j;
		}
		k=getchar();
	}
	while(k>='0'&&k<='9'){
		i=(i<<3)+(i<<1)+k-'0';
		k=getchar();
	}
	return i*j;
}
void s2(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9){
		s2(a/10);
	}
	putchar(a%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long a,b,c,d,e,f=0,g,h,i,j,k;
	a=s1();
	a=s1();
	b=s1();
	c=s1();
	c=s1();
	for(i=1;i<=b;i++){
		a1[i]=s1();
	}
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++){
			a2[i][j]=1000000000000000000;
		}
		a2[i][i]=0;
		d=s1();
		for(j=1;j<=d;j++){
			e++;
			f=s1();
			a4[e].a=i;
			a4[e].b=a3[f];
			a4[e].c=s1();
			a3[f]=e;
		}
	}
	for(i=1;i<=b;i++){
		j=a3[i];
		a5[0]=0;
		while(j){
			a5[0]++;
			a5[a5[0]]=a4[j].a;
			a6[a5[0]]=a4[j].c;
			j=a4[j].b;
		}
		for(j=1;j<=a5[0];j++){
			for(k=1;k<=a5[0];k++){
				a2[a5[j]][a5[k]]=min(a2[a5[j]][a5[k]],a6[j]+a6[k]);
			}
		}
	}
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++){
			for(k=1;k<=a;k++){
				a2[j][k]=min(a2[j][k],a2[j][i]+a2[i][k]);
			}
		}
	}
	for(i=1;i<=c;i++){
		d=s1();
		a5[0]=0;
		j=a3[d];
		e=a1[d];
		f=1000000000000000000;
		while(j){
			a5[0]++;
			a5[a5[0]]=a4[j].a;
			a6[a5[0]]=a4[j].c;
			j=a4[j].b;
		}
		d=s1();
		e+=a1[d];
		j=a3[d];
		while(j){
			for(k=1;k<=a5[0];k++){
				f=min(f,a4[j].c+a6[k]+a2[a5[k]][a4[j].a]);
			}
			j=a4[j].b;
		}
		s2(f+e);
		putchar('\n');
	}
	return 0;
} 
