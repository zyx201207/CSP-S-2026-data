#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],ans=-1,st[1010][1010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int la=1;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(b[t]==0){
			a[la]=t;
			la++;
		}
		b[t]++;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=la-1;i++){
			for(int j=i;j<=la-1;j++){
				if(j==i&&b[j]!=1){
					if(a[i]>ans){
						ans=a[i];
					}
					continue;
				}
				int x=a[i],y=a[j],cnt=0;
				for(int z=1;x!=0;z*=2){
					if(x%2==1&&y%2==1){
						cnt+=z;
					}
					x/=2;
					y/=2;
				}
				if(cnt>ans){
					ans=cnt;
				}
			}
		}
		cout<<ans;		
	}
	if(n==m){
		int mi=1000;
		for(int i=1;i<=la-1;i++){
			int x=a[i],w=1;
			while(x!=0){
				if(x%2==1){
					st[i][w]=2;
				}else{
					st[i][w]=1;
				}
				w++;
				x/=2;
			}
			if(mi>w-1){
				mi=w-1;
			}
		}
		ans=0;
		int flag=1,zb=1;
		for(int i=1;i<=mi;i++){
			flag=1;
			for(int j=1;j<=la-1;j++){
				if(st[j][i]==1){
					flag=0;
					break;
				}
			}
			if(flag){
				ans+=zb;
			}
			zb*=2;
		}
		cout<<ans;
	}
	/*
	for(int i=1;i<=la-1;i++){
		int x=a[i],w=1;
		for(int z=1;x!=0;z*=2){
			if(x%2==1){
				st[i][w]=2;
			}else{
				st[i][w]=1;
			}
			w++;
			x/=2;
		}
	}*/
	return 0;
}
