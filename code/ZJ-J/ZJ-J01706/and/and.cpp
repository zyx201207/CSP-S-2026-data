#include<bits/stdc++.h>
using namespace std;
int n,m;
int cntbl;
long long sumbl,ansbl;
struct node{
	long long num;
	int len;
}a[200005];

void baoli(int x){
	if(x>n){
		if(cntbl==m)
			ansbl=max(ansbl,sumbl);
		return;
	}
	if(cntbl>m) return;
	baoli(x+1);
	++cntbl;
	if(sumbl!=-1){
		long long lsum=sumbl;
		sumbl&=a[x].num;
		baoli(x+1);
		sumbl=lsum;
	}else{
		long long lsum=-1;
		sumbl=a[x].num;
		baoli(x+1);
		sumbl=lsum;
	}
	--cntbl;
}

bool specialA(){
	long long numA;
	for(int i=1;i<=n;++i){
		numA=a[i].num;
		while(numA>0){
			if(numA&1==0) return false;
			numA>>=1;
		}
	}
	return true;
}

bool specialB(){
	int w=1;
	bool flag=false;
	while(w<=n){
		if(n==w){
			flag=true;
			break;
		}
		w<<=1;
	}
	if(!flag) return false;
	for(int i=1;i<=n;++i){
		if(a[i].num!=i-1) return false;
	}
	return true;
}

bool cmp(node x,node y){
	return x.num>y.num;
}

long long randint(int x,int y){
	long long t=(rand()<<16)+rand();
	long long tt=t%(y-x+1)+x;
	return tt;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i].num);
	}
	if(n<=20){
		sumbl=-1;
		baoli(1);
		printf("%lld",ansbl);
	}else if(n==m){
		long long sumc=a[1].num;
		for(int i=2;i<=n;++i)
			sumc&=a[i].num;
		printf("%lld",sumc);
	}else if(n<=2000&&m==1){
		if(m==1){
			long long maxn=0;
			for(int i=1;i<=n;++i)
				maxn=max(maxn,a[i].num);
			printf("%lld",maxn);
		}
	}else if(specialA()){
		sort(a+1,a+n+1,cmp);
		printf("%lld",a[m].num);
	}else if(specialB()){
		printf("%lld",(n>>1)-1);
	}else{
		int time=150;
		long long maxn=0;
		while(time--){
			for(int i=1;i<=n;i++)
				swap(a[i],a[randint(i,n)]);
			long long summ=a[1].num;
			for(int i=2;i<m;++i)
				summ&=a[i].num;
			maxn=max(maxn,summ);
		}
		printf("%lld",maxn);
	}
	return 0;
}