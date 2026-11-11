#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=201000;
int c,t,n,st[N][25],stl[N][25];
ll d,a[N];
int dis(int u,int v){
	int ans=0;
	if(st[u][22]<v)return -1;
	else for(int i=22;i>=0;i--)if(st[u][i]<v)u=st[u][i],ans+=1<<i;
	return ans+1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)st[i][0]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		for(int i=0;i<22;i++){
			for(int j=1;j<=n;j++){
				st[j][i+1]=st[min(st[j][i],n)][i];
			}
		}
		for(int i=1;i<=n;i++)a[i]=-a[i];
		reverse(a+1,a+1+n);
		for(int i=1;i<=n;i++)stl[i][0]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		for(int i=0;i<22;i++){
			for(int j=1;j<=n;j++){
				stl[j][i+1]=stl[min(stl[j][i],n)][i];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int len=dis(i,j),tot=0;
				for(int k=1;k<len;k++){
					int p=i,q=n-j+1,l=k;
					for(int s=22;s>=0;s--){
						if(l>=(1<<s)){
							l-=1<<s;
							p=st[p][s],q=stl[q][s];
						}
					}
					q=n-q+1;
					if(q<p)tot+=p-q;
				}
				if(tot==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

