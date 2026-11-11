#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long a,b=0,c=0;
}x[50010];
bool cmp(node d,node e){
	return d.a<=e.a;
}
long long qzs(node f[]){
	long long vis[50010]={0};
	long long maxn=LONG_LONG_MIN,id;
	for(int i=1;i<=n;i++){
		vis[f[i].a]++;
		if(vis[f[i].a]>maxn){
			maxn=vis[f[i].a];
			id=f[i].a;
		}
	}
	return id;
}
int main(){
	cin>>n>>m;
	bool v[50010]={false},f=false;
	for(int i=1;i<=n;i++){
		cin>>x[i].a;
		if(!v[x[i].a])
			v[x[i].a]=true;
		else f=true;
	}
	sort(x+1,x+1+n,cmp);
	if(!f){
		for(int i=1;i<=n;i++){
			x[i].b=x[i+1].a-x[i].a;
			x[i].c+=x[i-1].c+x[i].b;
		}
		long long minn=LONG_LONG_MAX,ans=1;
		for(int i=1;i<=n;i++){
			if(m-x[i].c<minn&&m-x[i].c>0){
				minn=m-x[i].c;
				ans++;
			} 
		}
		cout<<ans<<endl;
		return 0;
	}else{
		long long zs=qzs(x);
		for(int i=1;i<=n;i++){
			x[i].b=x[i+1].a-zs;
			x[i].c+=x[i-1].c+x[i].b;
		}
		long long m,ans=0;
		for(int i=1;i<=n;i++){
			if(x[i].c==0)ans++;
			else{
				while(!x[i].a){
					x[i].a+=(x[i].a-zs>0?0:1);
					m--;
				}
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
