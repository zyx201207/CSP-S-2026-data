#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,d,e,q[2888888],ih,m=0,a[288888];
int dfs(int p,int aim,int passi){
	if(passi>ih)return 0;
	if(p>=aim){
		if(p>aim)return 0;
		return 1;
	}
	int as=0;
	for(int i=p+1;i<=aim;i++){
		if(q[i]-q[p]<=d)as+=dfs(i,aim,passi+1);
		else{
			break;
		}
		if(as>2)return 3;
	}
	return as;
}
bool check(int x,int y){
	int dis=q[y]-q[x];
	int dei=y-x-1;
	if(dis<=d||dei<=1)return 0;
	for(int i=x+1;i<=y;i++){
		if(q[i]-q[i-1]>d)return 0;
	}
	ih=0;
	int s=x;
	bool ff=0;
	while(s!=y){
		int k=0;
		for(int i=s;i<n;i++){
			if(q[i]-q[s]>d){
				k=i-1;
				break;
			}
			if(i==y){
				ff=1;
				break;
			}
		}
		ih++;
		s=k;
		if(ff)break;
	}
	return dfs(x,y,0)==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>e;
	while(e--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>q[i];
		}
		if(c==12||c==11){
			int de=q[1]-q[0],ans=0;
			int k1=d/de;
			if(k1<2){
				a[m++]=0;
				continue;
			}
			for(int i=0;i<n;i++){
				for(int j=i+k1+1;j<n;j++){
					if((j-i)%k1==0)continue;
					if(check(i,j)){
						ans++;
					}
				}
			}
			a[m++]=ans;
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		a[m++]=ans;
	}
	for(int i=0;i<m;i++){
		cout<<a[i]<<'\n';
	}
	return 0;
}
