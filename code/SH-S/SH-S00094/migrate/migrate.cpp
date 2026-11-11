#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,t,n,d,x[N],v[N],cnt[N],j,g[N],s,y,h,f=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>x[i];
		j=1;
		h=-1;
		f=0;
		for(int i=1;i<=n;++i){
			while(j<n&&x[j+1]-x[i]<=d)
				j++;
			g[i]=j;
			if(i==2)
				h=x[2]-x[1];
			if(i>2&&h!=x[i]-x[i-1]){
				f=1;
			}
		}
		s=0;
		if(n>5000&&f==0){
			if(g[1]!=1&&g[1]!=2){
				y=g[1]*2-2;
				s=n-y+1;
				if(s<0)
					s=0;
			}
		}
		else{
			for(int i=1;i<=n;++i){
				cnt[i]=1;
				v[i]=0;
				for(int j=i+1;j<=n;++j){
					cnt[j]=0;
					v[j]=1e9;
				}
				for(int j=i;j<=n;++j){
					if(v[j]==1e9)
						break;
					if(cnt[j]==2)
						s++;
					for(int k=g[j]-2;k<=g[j];++k){
						if(k>j){
							if(v[k]>v[j]+1){
								v[k]=v[j]+1;
								cnt[k]=0;
							}
							if(v[k]==v[j]+1)
								cnt[k]+=cnt[j];
						}
					}
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
