#include<bits/stdc++.h>
#define maxn 500005
using namespace std;

bool memjfs;
void read(long long &numx){
	register bool is_minus=0;
	register char xxx=getchar();
	numx=0;

	for(;xxx<'0'||xxx>'9';xxx=getchar()){
		if(xxx=='-'){
			is_minus=1;
		}
	}

	for(;xxx>='0'&&xxx<='9';xxx=getchar()){
		numx=(numx<<3)+(numx<<1)+(xxx^48);
	}

	if(is_minus){
		numx=-numx;
	}
}
bool flag[maxn];
long long a[maxn];
long long ans[maxn];
long long n,m;
stack<long long > d;
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(n);read(m);
	
	for(long long i=1;i<=n;i++){
		read(a[i]);
	}
	
	for(long long i=1;i<=n;i++){
		memset(flag,false,sizeof(flag));
		
		long long cnt=0;
		for(long long j=i;j<=n;j++){
			if(flag[a[j]]){
				while(!d.empty()&&d.top()!=a[j]){
					flag[d.top()]=0;
					d.pop();
				}
			} else {
				flag[a[j]]=1;
				d.push(a[j]);
			}
		}
		
		while(!d.empty()){
			ans[d.top()]++;
			d.pop();
		}
	}
	
	for(long long i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}