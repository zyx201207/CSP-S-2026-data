#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace io{
	int read(){
		int x=0,y=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') y=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		return x*y;
	}
	void output(int x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9) output(x/10);
		putchar(x%10|48);
	}
}
#define read() io::read()
#define output(x) io::output(x)
namespace Czming__{
	int n,lst[2000001],pre[2000001],ok,ma[2000001],L,R,Lr,Rl;
	int a[2000001],d,answer,p,ne,sum1,sum2;
	int calc(int a,int b){
		return a-a/b;
	}
	void init(){return ;}
	void work1(){
		vector<int> L[5001],R[5001];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				L[i].push_back(0);
				R[i].push_back(0);
			}
		}
		answer=0;
		p=1;
		for(int i=1;i<=n;i++){
			while(p<n&&a[p+1]-a[i]<=d) p++;
			lst[i]=p;
		}
		p=n;
		for(int i=n;i;i--){
			while(p>1&&a[i]-a[p-1]<=d) p--;
			pre[i]=p;
		}
		for(int l=1;l<=n;l++){
			ne=l;
			ok=l;
			sum1=0;
			while(ne){
				if(lst[ne]==ne){
					ma[l]=ne;
					break;
				}
				ne=lst[ne];
				for(int j=ok+1;j<=ne;j++) L[l][j]=sum1;
				ok=ne;
				sum1+=ne;
				if(ne==n){
					ma[l]=n;
					break;
				}
			}
		}
		for(int r=1;r<=n;r++){
			ne=r;
			ok=r;
			sum2=0;
			while(ne){
				if(pre[ne]==ne) break;
				ne=pre[ne];
				for(int j=ne;j<ok;j++) R[j][r]=sum2;
				ok=ne;
				sum2+=ne;
				if(ne==1) break;
			}
		}
		answer=0;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=ma[l];r++){
				if(L[l][r]-R[l][r]==1) answer++;
			}
		}
		output(answer);
		puts("");
	}
	void work2(){
		int cha;
		if(n==1){
			puts("0");
			return ;
		}
		cha=a[n]-a[n-1];
		d=d/cha;
		if(d==1||d==0){
			puts("0");
			return ;
		}
		answer=0;
		for(int i=1;i<=n;i++){
			if(n-i+1>=2*d) answer++;
		}
		output(answer);
		puts("");
	}
	int calc(int l1,int r1,int l2,int r2){
		int sums=0;
		if(l2<l1) l2=l1;
		if(l1<l2){
			if(r1<=l2) return (r1-l1+1)*(r2-l2+1);
			sums+=(l2-l1+1)*(r2-l2+1);
			l1=l2;
		}
		if(r2<r1) r1=r2;
		return sums+(r2-l1+1+r2-r1+1)*(r1-l1+1)/2;
	}
	void work3(){
		answer=0;
		p=1;
		for(int i=1;i<=n;i++){
			while(p<n&&a[p+1]-a[i]<=d) p++;
			lst[i]=p;
		}
		p=n;
		for(int i=n;i;i--){
			while(p>1&&a[i]-a[p-1]<=d) p--;
			pre[i]=p;
		}
		L=1;
		R=n;
		while(true){
			Lr=L;
			while(Lr<n&&lst[Lr+1]==lst[L]) Lr++;
			Rl=R;
			while(Rl>1&&pre[Rl-1]==pre[R]) Rl--;
			if(lst[L]-pre[R]==1) answer+=calc(L,Lr,Rl,R);
			L=Lr+1;
			R=Rl-1;
			if(L>R) break;
		}
		output(answer);
		puts("");
	}
	void work(int id){
		n=read();
		d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(id<=10){
			work1();
			return ;
		}
		if(id==11||id==12){
			work2();
			return ;
		}
		if(id==13||id==14){
			work3();
			return ;
		}
		return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id=read(),T=read();
	Czming__::init();
	while(T--) Czming__::work(id);
	return 0;
}
