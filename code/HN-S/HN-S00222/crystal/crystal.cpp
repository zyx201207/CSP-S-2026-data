#include<bits/stdc++.h>
using namespace std;
long long a1[500010],a2[500010];
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
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k;
	a=s1();
	b=s1();
	for(i=1;i<=a;i++){
		a1[i]=s1();
	}
	sort(a1+1,a1+1+a);
	for(i=1;i<=a;i++){
		a2[i]=a2[i-1]+a1[i];
	}
	c=2;
	d=a+1;
	e=(c+d)/2;
	while(c<d){
		f=0;
		for(j=e;j<=a;j++){
			if(a1[j]*e-(a2[j]-a2[j-e])<=b){
				f=1;
				break;
			}
		}
		if(f==1){
			c=e+1;
		}else{
			d=e;
		}
		e=(c+d)/2;
	}
	s2(e-1);
	return 0;
} 
