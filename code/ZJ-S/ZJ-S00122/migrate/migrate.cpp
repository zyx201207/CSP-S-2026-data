#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s*f;
}
long long n,x[2000005],c,t,d,z,nxt[2000005],cnt[2000005],dis[2000005];
//bool pd[2000005];
queue<long long> Q;
bool check(long long A,long long B){
	if(x[B]-x[A]<=d){
		return false;
	}
	Q.push(A);
	bool p=false;
	while(!Q.empty()){
		long long f=Q.front();
		Q.pop();
		for(int i=f+1;i<=B;i++){
			if(x[i]-x[f]<=d){
				if(dis[i]==0){
					dis[i]=dis[f]+1;
					cnt[i]=1;
					Q.push(i);
					continue;
				}
				if(dis[f]+1>dis[i]){
					continue;
				}
				else if(dis[f]+1==dis[i]){
					cnt[i]++;
				}
				else{
					dis[i]=dis[f]+1;
					cnt[i]=1;
				}
				Q.push(i);
			}
			else{
				break;
			}
		}
	}
	if(dis[B]==0){
		return false;
	}
//	for(int i=A;i<=B;i++){
//		if(cnt[i]==2){
//			if(p){
//				return false;
//			}
//			else{
//				p=true;
//			}
//		}
//		if(cnt[i]>=3){
//			return false;
//		}
//	}
	if(cnt[B]==2){
		return true;
	}
	else{
		return false;
	}
//	return p;
}
int main(){
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	for(;t;t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(n==1 || n==2){
			cout<<"0"<<endl;
			continue;
		}
		if(c==11 || c==12){
			long long NUM=d/(x[2]-x[1]),CNT=0;
//			if(t==11){
//				cout<<NUM<<" "<<d<<" "<<x[2]-x[1]<<endl;
//			}
			for(int i=1;;i++){
				if(i+2*NUM-1>n || NUM<=0 || NUM<2){
					break;
				}
				else{
					CNT++;
				}
			}
			cout<<CNT<<endl;
			continue;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(x[j]-x[i]>d){
//					nxt[i]=j-1;
//					break;
//				}
//			}
//			if(x[n]-x[i]<=d){
//				nxt[i]=n;
//			}
//			if(nxt[i]==0){
//				nxt[i]=-1;
//			}
//		}
		for(int u=1;u<=n;u++){
			for(int v=u+3;v<=n;v++){
				for(int i=u;i<=v;i++){
					dis[i]=0;
					cnt[i]=0;
				}
				if(check(u,v)){
//					cout<<u<<" "<<v<<endl;
					z++;
				}
//				for(int i=u;i<=v;i++){
//					cout<<cnt[i]<<" "<<dis[i];
//				}
//				cout<<endl;
			}
		}
		for(int i=1;i<=n;i++){
//			nxt[i]=0;
			dis[i]=0;
			cnt[i]=0;
		}
		cout<<z<<endl;
		z=0;
	}
	return 0;
}