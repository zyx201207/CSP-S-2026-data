#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,k=30;
int a[N],p[32];
bool cmp(int x,int y){
	int t=k;
	for(;t>=0;t--){
		if(((x&(1<<t))==(1<<t))&&((y&(1<<t))==0)){
			return 1;
		}
		if(((y&(1<<t))==(1<<t))&&((x&(1<<t))==0)){
			return 0;
		}
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=(1<<32)-1,now=30;
	for(k=30;k>=0;k--){
		now=30;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			while(a[i]<(1<<now)){
				now--;
			}
			if(!p[now+1]){
				p[now+1]=i-1;
			} 
		}
		for(int i=0;i<=n;i++){
			if(!p[i]){
				p[i]=p[i-1];
			}
		}
		if(p[k]>=m||p[k]==0){
			for(int i=1;i<=m;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}