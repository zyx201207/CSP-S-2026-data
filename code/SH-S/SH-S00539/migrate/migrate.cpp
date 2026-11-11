#include <bits/stdc++.h>
char buf[1000009],*paa=buf,*pd=buf;
#define getchar() ((paa==pd)&&(paa=buf,pd=buf+fread(buf,1,1000000,stdin),paa==pd)?EOF:(*paa++))
inline long long read() {
	char op=getchar();
	int w=1;
	while(op<'0'||op>'9') {
		if(op=='-') w=-1;
		op=getchar();
	}
	long long x=0;
	while(op>='0'&&op<='9') {
		x=x*10+op-'0';
		op=getchar();
	}
	return w*x;
}
int C,T,N,jp[2000009],f1[2000009],f2[2000009];
long long D,a[2000009],as;
void sv(int l,int r) {
	//printf("%d %d\n",l,r);
	//for(int j=l;j<=r;j++) printf("%d ",jp[j]);
	//printf("\n");
	for(int j=r;j>l;j--) {
		if(jp[j]==r) {
			f1[j]=f2[j]=0;
			continue;
		}
		int x=jp[j],y=jp[jp[j]];
		if(a[y]-a[x-1]<=D) {
			//ok
			if(a[y]-a[x-2]<=D||a[x-1]-a[j-1]<=D) {
				f1[j]=f2[j]=0;
			} else {
				f1[j]=0;f2[j]=f1[x];	
			}
		} else {
			f1[j]=f1[x];
			f2[j]=f2[x];
		}
		f1[j]+=y-jp[x-1];
		if(a[x-1]-a[j-1]>D) {
			f2[j]+=jp[x-1]-std::max(jp[x-2],x);
		}
//		for(int i=x+1;i<=y;i++) {
			//j x i
//			if(a[i]-a[x-1]<=D) {
//				if(a[i]-a[x-2]>D&&a[x-1]-a[j-1]>D) f2[j]++;
//			} else {
		//		f1[j]++;
//			}
//		}
	}

	for(int j=l;j<=r;j++) {
		if(jp[j]==r) continue;
		int x=jp[j],y=jp[jp[j]];
		if(a[y]-a[x-1]<=D) {
			if(a[y]-a[x-2]>D)
				as+=f1[jp[j]];
		} else {
			as+=f2[jp[j]];			
		}
		if(x>=j+2)
			as+=jp[x-1]-std::max(jp[x-2],x);
//		for(int i=x+1;i<=y;i++) {
			//j x i
//			if(a[i]-a[x-1]<=D) {
//				if(a[i]-a[x-2]>D&&x>2) as++;
//			} 
//		}
	}
//	printf("%lld\n",as);
//	for(int j=l;j<=r;j++) as+=f2[j];
}	
signed main(void) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	while(T--) {
		as=0;
		N=read();D=read();
		for(int i=1;i<=N;i++) {
			a[i]=read();
		}
		int p=N;
		for(int i=N;i>=1;i--) {
			while(a[p]-a[i]>D) {
				p--;
			}
			jp[i]=p;
		}
		int la=1;
		for(int i=1;i<=N;i++) {
			if(jp[i]==i) {
				sv(la,i);
				la=i+1;
			}
		}
		printf("%lld\n",as);
	}
}
