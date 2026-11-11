#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
long long ans;
bool b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	int x=0,s=1;
	while(maxn){
		maxn/=2;
		x++;
		s*=2;
	}
	s/=2;
	x--;
	for(int i=x;i>=0;i--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!b[i]){
				if(a[i]&s){
					cnt++;
				}else{
					c[i]=1;
				}
			}
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++) if(c[i]) b[i]=1;
			ans+=s;
			//cout<<i<<endl;
		}
		for(int i=1;i<=n;i++) c[i]=0;
		s/=2;
	}
	cout<<ans<<endl;
	return 0;
} 