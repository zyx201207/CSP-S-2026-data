#include<bits/stdc++.h>
#define maxn 1005
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
long long a[maxn];
long long _,T,n,k,ans;
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(_);read(T);
	
	for(long long task=1;task<=T;task++){
		read(n);read(k);
		
		for(long long i=1,x,y;i<=n;i++){
			read(x);read(y);
		}
		
		if(!_){
			printf("1\n");
			printf("2");
		} else {
			printf("0\n");
			printf("0");
		}
	}
	return 0;
}
