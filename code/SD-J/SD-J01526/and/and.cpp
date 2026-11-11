#include<bits/stdc++.h>
using namespace std;

long long n,m,a[10000086],v[10000086],maxx,b[2000086],ff;

void dfs(long long idx,long long c){
	if(c<=maxx){
		return;
	}
	if(idx==m+1){
		maxx=c;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			long long y=c;
			y&=a[i];
			dfs(idx+1,y);
			v[i]=0;
		}
	}
}

bool pan(long long x){
	long long l=0,y=x;
	while(x){
		x&=x-1;
		l++;
	}
	if(l==1){
		b[y]++;
	}else{
		ff=1;
	}
	if((long long)pow(2,l)-1==y){
		return 1;
	}
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!pan(a[i])){
			f=0;
		}
	}if(f){
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m];
		return 0;
	}
	if(!f){
		dfs(1,2147483647);
		cout<<maxx;
	}else if(ff){
		for(int i=1100000;i>=1;i--){
			if(b[i]>=m){
				cout<<i;
			}
		}
	}
	return 0;
}
