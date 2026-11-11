#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool bk[200001];
int n,m;

long long seek(int t){
	long long ans=0;
	vector<int>v[31];
	for(int i=1;i<=n;++i){
		if(t!=31){
			if(!(a[i]&1<<t))bk[i]=1;
		}
		long long bs=0;
		while((1<<bs)<=a[i]){
			if(((1<<bs)&a[i])&&!bk[i]){
				v[bs].push_back(i);
			}
			bs++;
		}
	}
	for(int i=t-1;i>=0;--i){
		if(v[i].size()>=m){
			ans+=(1<<i);
			ans+=seek(i);
			break;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		long long bs=0;
		scanf("%lld",a+i);
	}
	printf("%lld",seek(31));
}
