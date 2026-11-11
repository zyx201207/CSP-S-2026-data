#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

long long in(){
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

long long t,c;
long long n,d;
long long x[N],aa[N],ans=0,bb[N],vis[N];
queue<long long> q;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=in();d=in();
		
		for(int i=1;i<=n;i++){
			x[i]=in();
			bb[i]=0;
			vis[i]=0;
			aa[i]=0;
		}
		for(int i=1;i<=n;i++){
			aa[i]=lower_bound(x+1,x+n+1,x[i]+d)-(x);
//			if(aa[i]==n)aa[i]=n-i+1;
//			else aa[i]=aa[i]-i-1;
			while(x[aa[i]]-x[i]>d)aa[i]--;
			if(aa[i]>n)aa[i]=n;
//			aa[i]=aa[i]-i;
//			cout<<aa[i]<<" ";
		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			long long a1=aa[i];
			long long b1=a1-1;
			long long c1=aa[b1];
			if(aa[i]-i>2){
				if(c1-aa[a1-2]>0){
					bb[i]+=c1-aa[a1-2];
					ans+=c1-aa[a1-2];	
				}
			}else if(aa[i]-i==2){
				if(c1-a1>0){
					ans+=c1-a1;
					bb[i]+=c1-a1;
				}
			}else if(aa[i]-i==1){
				if(i==n-1)continue;
				vis[i]=1;
				q.push(i);
//				cout<<i<<endl;
			}
		}
//		for(int i=1;i<=n;i++){
//			qian[i]=qian[i-1]+vis[i];
//		}
		long long tot=0;
		while(!q.empty()){
			long long x=q.front();
			q.pop();
			long long sss=0;
			bool bo=0;
			int l,r;
//			cout<<x<<endl;
			for(long long i=x+2;i<=aa[x+1];i++){
				if(vis[i])vis[i]++;
				sss+=bb[i];
				
			}
			ans+=sss*(vis[x]-1);
			vis[x]=0;
		}
//		for(int i=1;i<=n;i++){
//			cout<<bb[i]<<" ";
//		}
//		cout<<endl;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 2
2 4 6 7 8 9 10

1 2 3 4 5 6 7 8
zhojia2
zhojia1houjia2

kedao2 2luchong

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/