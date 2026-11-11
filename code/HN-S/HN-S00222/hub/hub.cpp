#include<bits/stdc++.h>
using namespace std;
long long a1[110],a3[110],a4[110][110],a5[110],a6[110],a7[110],a8[110],a9;
struct t1{
	long long a,b;
}a2[210];
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
	long long i=a1[a],j;
	a6[a]=b;
	a7[0]++;
	a7[a7[0]]=a;
	while(i){
		if(a2[i].a!=b){
			s3(a2[i].a,a,c);
			for(j=1;j<=c;j++){
				a4[a][j]=min(a4[a][j],a4[a2[i].a][j]+1);
			}
		}
		i=a2[i].b;
	}
}
void s4(long long a,long long b,long long c){
	long long i;
	for(i=1;i<=c;i++){
		a4[a][i]=min(a4[a][i],a4[b][i]+1);
	}
	i=a1[a];
	while(i){
		if(a2[i].a!=b){
			s4(a2[i].a,a,c);
		}
		i=a2[i].b;
	}
}
void s5(long long a,long long b,long long c,long long d){
	long long i,j,k,l=0;
	if(a>c){
		for(i=1;i<=c;i++){
			k=1000000000;
			for(j=1;j<=a5[0];j++){
				k=min(k,a4[i][a5[j]]);
			}
			l=max(l,k);
		}
		a9=min(a9,l);
		return;
	}
	if(b>0&&(d!=2||a8[a6[a7[a]]]==1)){
		a5[0]++;
		a5[a5[0]]=a7[a];
		a8[a7[a]]=1;
		if(a8[a6[a7[a]]]==1){
			s5(a+1,b-1,c,d);
		}else{
			s5(a+1,b-1,c,d+1);
		}
		a8[a7[a]]=0;
		a5[0]--;
	}
	if(c-a>=b){
		s5(a+1,b,c,d);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k,l,m;
	l=s1();
	l=s1();
	for(m=1;m<=l;m++){
		a=s1();
		b=s1();
		for(i=1;i<=a;i++){
			a1[i]=0;
		}
		for(i=1;i<a;i++){
			a2[i*2].a=s1();
			a2[i*2-1].a=s1();
			a2[i*2].b=a1[a2[i*2-1].a];
			a2[i*2-1].b=a1[a2[i*2].a];
			a1[a2[i*2].a]=i*2-1;
			a1[a2[i*2-1].a]=i*2;
		}
		if(a==b){
			putchar('0');
			putchar('\n');
		}else if(a-b<=3){
			putchar('1');
			putchar('\n');
		}else{
			for(i=0;i<=a;i++){
				for(j=0;j<=a;j++){
					a4[i][j]=1000000000;
				}
				a4[i][i]=0;
			}
			s3(1,0,a);
			s4(1,0,a);
			a9=1000000000;
			s5(1,b,a,0);
			cout<<a9<<'\n';
		}
	}
	return 0;
}
