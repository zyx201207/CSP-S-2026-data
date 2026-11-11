#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans;
int a[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=31;i>=0;i--){
		int op=(1 << i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&op)&&!vis[j]) cnt++;
		}
		if(cnt>=m){
			ans+=op;
			for(int j=1;j<=n;j++){
				if((a[j]&op)!=op) vis[j]=true;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
