#include<bits/stdc++.h>
using namespace std;
long long rock[510001];
long long u[510001];
int maxk(long long a,long long b){
	if(a>b)return a;
	return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=0,nowmaxn=0;
	cin>>n>>m;
	bool p=1,k=1;
	for(long long i=1;i<=n;i++){
		string qw;
		//scanf("%s",&qw);
		cin>>qw;
		bool qwe=0;
		if(qw[0]=='-')qwe=1;
		if(!qwe)rock[i]=pow(10,12);
		long long now=0;
		for(long long j=qw.size()-1;j>=0+qwe;j--){
			rock[i]+=(qw[j]-'0')*pow(10,now);now++;
		}if(qwe)rock[i]=pow(10,12)-rock[i];
    }sort(1+rock,rock+1+n);
	for(long long i=1;i<=n;i++){
    	if(rock[i]!=rock[i-1]+1&&p){
			p=0;
		}if(rock[i]!=rock[i-1]+rock[2]-rock[1]&&i!=1&&k){
			k=0;
		}
		if(i==1)u[i]=0;
		else u[i]=i-1+u[i-1];
		if(p&&u[i]<=m)nowmaxn=i;
		if(k&&u[i]*(rock[2]-rock[1])<=m)nowmaxn=i;
	}
	if(p||k){
		cout<<nowmaxn;
		return 0;
	}
	for(long long i=n;i>=1;i--){
		long long need=0,now=1;
		for(long long j=i-1;j>=1;j--){
			need+=rock[i]-rock[j];
			if(need<=m){
				now++;
			}else{
				break;
			}
		}maxn=maxk(maxn,now);
		if(maxn>=i-1)break;
	}cout<<maxn;
	return 0;
} 