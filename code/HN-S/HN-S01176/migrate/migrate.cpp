#include<bits/stdc++.h>

using namespace std;

long long a[2000010],n,cc,t,d,ans;
int b[2000010],w=1,to=0,c[2000010],lu[2000010];

void bfs(int x){
//			cout<<1;
	b[w]=x;
	for(int i=1;i<=n;i++){
		c[i]=0;
		lu[i]=0;
	}
	while(to<w){
		to++;
		for(int i=b[to]-1;i>0;i--){
			if(a[b[i]]-a[i]>d)break;
			if(c[i]==0){
				w++;
				c[i]=c[b[to]]+1;
			}
			if(c[i]!=c[b[to]]+1)continue;
			if(lu[i]==2)ans++;
			if(lu[i]==3)ans--;
			lu[i]++;
		}
	}
	return;
}
int main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			bfs(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}


