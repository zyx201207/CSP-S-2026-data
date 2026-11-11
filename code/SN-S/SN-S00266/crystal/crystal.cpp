#include<bits/stdc++.h>
using namespace std;
int q[3],n;
long long a[500001];
bool f[500001];
long long ans;
long long maxn;
long long zjia(long long m,int g){
	f[500001]={false};
	ans=1;
	f[g]=true;
	q[1]=g-1;q[2]=g+1; 
	while(1){
		if(q[1]<=0&&q[2]>n)break;
		if(q[1]<=0){
			long long x2=a[q[2]]-a[g];
			if(x2<=m){
				ans++;m-=x2;f[q[2]]=1;q[2]=q[2]+1;
			}
			else if(x2>m)break;
		}
		else if(q[2]>n){
			long long xx=a[g]-a[q[1]];
			if(xx<=m){
				ans++;m-=xx;f[q[1]]=1;q[1]=q[1]-1;
			}
			else if(xx>m)break;
		}
		else{
			long long xx=a[g]-a[q[1]];
			long long x2=a[q[2]]-a[g];
			if(xx<=x2&&xx<=m){
				ans++;m-=xx;f[q[1]]=1;q[1]=q[1]-1;
			}
			else if(xx==x2&&x2<=m){
				ans++;m-=x2;f[q[2]]=1;q[2]=q[2]+1;
			}
			else if(xx>x2&&x2<=m){
				ans++;m-=x2;f[q[2]]=1;q[2]=q[2]+1;
			}
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=0x7fffffff;
	int chong=a[1],ccnt=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,zjia(m,i));
	}
	cout<<maxn;
	return 0;
}
