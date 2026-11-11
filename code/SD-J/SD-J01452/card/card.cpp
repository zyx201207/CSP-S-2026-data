#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=3e5+10;
LL n,m,c[N],ans[M],l;
queue<LL> a;
bool f[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		memset(f ,0,sizeof f);
		for(int j=i;j<=n;j++){
			//cout<<c[j]<<endl;
		if(f[c[j]]){
			f[c[j]]=0;
			while(!a.empty()){
			//cout<<a.front()<<" ";
			f[a.front()]=0;
			a.pop();
		}
		}
		f[c[j]]=1;
		a.push(c[j]);
	}
		while(!a.empty()){
			ans[a.front()]++;
			a.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
