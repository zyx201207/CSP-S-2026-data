//NO!!!

#include<bits/stdc++.h>
using namespace std;
const int N=5e3+2;
int c,t,n,l[N],r[N],sing1[N],sing2[N],ll[N];
long long d,x[N],ans;
deque<int>q;
int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=0;o<t;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i],ll[i]=0;
		for(int i=1,k=1;i<=n;i++){
			while(x[i]-x[k]>d)k++;
			l[i]=k,sing1[i]=1;
		}
		for(int i=1,lj=1,rj=0,sum=0;i<=n;i++){
			while(lj<=n&&x[lj]<x[l[i]]-d)sum-=sing1[lj++];
			while(rj<n&&(l[i]==n||x[rj+1]<x[l[i]+1]-d))sum+=sing1[++rj];
			sing1[i]=i-l[i]+1+sum;
		}
		for(int i=n,k=n;i;i--){
			while(x[k]-x[i]>d)k--;
			r[i]=k,sing2[i]=1;
		}
		for(int i=n,lj=n+1,rj=n,sum=0;i;i--){
			while(rj>=1&&x[rj]>x[r[i]]+d)sum-=sing2[rj--];
			while(lj>1&&(r[i]==1||x[lj-1]>x[r[i]-1]+d))sum+=sing2[--lj];
			sing2[i]=r[i]-i+1+sum;
		}
		ans=0;
		for(int i=1;i<=n;i++)ll[l[i]]+=sing2[i];
		for(int i=1;i<=n;i++)
			ans+=(long long)sing1[i]*ll[r[i]-1];
		cout<<ans<<"\n";
	}
	return 0;
}
