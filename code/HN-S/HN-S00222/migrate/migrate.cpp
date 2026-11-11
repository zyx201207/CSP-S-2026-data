#include<bits/stdc++.h>
using namespace std;
long long a1[5010],a3,a4;
struct t1{
	long long a,b,c,d,e,f,g,h,i,j,k;
}a2[20010];
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
void s3(long long a,long long b,long long c){
	long long i=(b+c)/2;
	a2[a].a=b;
	a2[a].b=c;
	if(b!=c){
		s3(a*2,b,i);
		s3(a*2+1,i+1,c);
	}
}
void s4(long long a,long long b){
	a2[a].c=1000000000000000000;
	a2[a].d=0;
	if(a2[a].a==a2[a].b){
		return;
	}
	if(b<=a2[a*2].b){
		s4(a*2,b);
	}
	s4(a*2+1,b);
}
void s5(long long a,long long b,long long c,long long d,long long e){
	if(b<=a2[a].a&&a2[a].b<=c){
		if(a2[a].c>d){
			a2[a].c=d;
			a2[a].d=e;
		}else if(a2[a].c==d){
			a2[a].d+=e;
		}
		return;
	}
	if(a2[a*2].b>=b){
		s5(a*2,b,c,d,e);
	}
	if(a2[a*2+1].a<=c){
		s5(a*2+1,b,c,d,e);
	}
}
void s6(long long a,long long b){
	if(a3>a2[a].c){
		a3=a2[a].c;
		a4=a2[a].d;
	}else if(a3==a2[a].c){
		a4+=a2[a].d;
	}
	if(a2[a].a==a2[a].b){
		return;
	}
	if(a2[a*2].b>=b){
		s6(a*2,b);
	}else{
		s6(a*2+1,b);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k,l,m;
	l=s1();
	l=s1();
	for(m=1;m<=l;m++){
		a=s1();
		s3(1,1,a);
		b=s1();
		c=0;
		for(i=1;i<=a;i++){
			a1[i]=s1();
		}
		j=1;
		for(i=1;i<=a;i++){
			while(j<=a&&(a1[j]-a1[i])<=b){
				j++;
			}
			a1[i]=j-1;
		}
		for(i=1;i<a;i++){
			s4(1,i+1);
			if(a1[i]==i){
				continue;
			}
			s5(1,i+1,a1[i],1,1);
			for(j=i+1;j<a;j++){
				if(a1[j]==j){
					break;
				}
				a3=1000000000000000000;
				a4=0;
				s6(1,j);
				s5(1,j+1,a1[j],a3+1,a4);
				if(a4==2){
					c++;
				}
			}
			a3=1000000000000000000;
			a4=0;
			s6(1,j);
			if(a4==2){
				c++;
			}
		}
		cout<<c<<'\n';
	}
	return 0;
}
