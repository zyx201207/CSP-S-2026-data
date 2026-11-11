#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c;long long x=0,f=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')f=-f;
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	return x*f;
}
int c,t;
int n;long long d;
long long a[2000006];
bool flag[2000006];
//int next;
long long ans;
int b[2000006],l=0;
void solves(int L,int R){
//	printf("solves %d %d\n",L,R);
	for(int i=L;i<R;++i)flag[i]=0;
	for(int i=L;i<R-3;++i){
		if(a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d){
			flag[i+1]=flag[i+2]=true;
		}
	}
	//___**__ available
	bool last=false;
	int cnt=0;
	l=0;
	for(int i=L;i<R;++i){
		if(flag[i]==last){
			++cnt;
		}else{
			b[l]=cnt;
			cnt=1;
			++l;
			last=flag[i];
		}
	}
	b[l]=cnt;
	++l;
	if(l==1)return;
	if(l==3){
		if(b[1]==2){
			ans+=b[0]*b[2];
		}else{
			ans+=b[0]+b[2]+(b[1]-3);
		}
		return;
	}
	if(b[1]==2){
		ans+=b[0]*(b[2]+2);
	}else{
		ans+=b[0]+(b[2]+2)+b[1]-3;
	}
	if(b[l-2]==2){
		ans+=b[l-1]*(b[l-3]+2);
	}else{
		ans+=b[l-1]+(b[l-3]+2)+b[l-2]-3;
	}
	for(int i=3;i<l-2;i+=2){
		if(b[i]==2){
			ans+=(b[i-1]+2)*(b[i+1]+2);
		}else{
			ans+=(b[i-1]+2)+(b[i+1]+2)+b[i]-3;
		}
	}
	return ;
}
void solve(){
	n=read();d=read();
	ans=0;
	for(int i=0;i<n;++i){
		a[i]=read();
	}
	int st=0;
	for(int i=1;i<n;++i){
		if(a[i]-a[i-1]>d){
			solves(st,i);
			st=i;
		}
	}
	solves(st,n);
	printf("%lld\n",ans);
	return;
}
bool visit[2000006];
int dfs(int now,int to,int deep,int minnstep){
	if(deep>minnstep)return 0;
	if(a[to]-a[now]<=d)return (deep+1<=minnstep);
	int summm=0;
	for(int i=now+1;i<=to&&a[i]-a[now]<=d;++i){
		summm+=dfs(i,to,deep+1,minnstep);
		if(summm>2)return 3;
	}
	return summm;
}
int countpath(int from,int to){
	int minnstep=1,st=from;
	for(int i=from;i<=to;++i){
		if(a[i]-a[st]>d){
			st=i;
			minnstep++;
		}
	}
//	printf("minstep:%d ",minnstep);
	return dfs(from,to,0,minnstep);
}
void solve2(){
	n=read();d=read();
	ans=0;
	for(int i=0;i<n;++i){
		a[i]=read();
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(a[j]-a[j-1]>d)break;
	//		printf("%d->%d:%d\n",i,j,countpath(i,j));
			if(countpath(i,j)==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		if(c<=10)solve2();
		else solve();
	}
	return 0;
}
