#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAXN = 500010;
long long n,m;
long long presum[MAXN];
long long val[MAXN];
long long fdml(long long pre[]){
	long long mxl=0;
	long long leng=0;
	for(long long i=0;i<n-1;i++){
		if(pre[i]==pre[i+1]){
			leng++;
		}else{
			mxl=max(mxl,leng+1);
			leng=0;
		}
	}return mxl;
}
long long dfs(long long v,long long pre[]){
	if(v==0){
		return fdml(pre);
	}
	long long mxv=-1e18;
	bool flag=0;
	for(long long i=0;i<n-1;i++){
		if(pre[i+1]-pre[i]<=v && pre[i+1]-pre[i]>0){
			flag=1;
			long long pre1[MAXN];
			for(long long j=0;j<n;j++){
				pre1[j]=pre[j];
			}
			pre1[i]=pre1[i+1];
			mxv=max(mxv,dfs(v-(pre[i+1]-pre[i]),pre1));
		}
	}
	if(flag==0){
		return fdml(pre);
	}
	return mxv;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>val[i];
	}
	sort(val,val+n);
	cout<<dfs(m,val);
	return 0;
}
