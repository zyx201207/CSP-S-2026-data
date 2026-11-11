#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,T,f;
int a[N],b[N];
int mp[N],res[N];
int q[N][5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;T=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1]) f=1;
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		int x,y;
		for(int i=n;i>=1;i--){
			if(a[i]==1) x=i;
			else y=i;
			q[i][1]=x;q[i][2]=y;
		}
		res[a[n]]=n;
		for(int i=1;i<=n;i++){
			if(a[n]==1&&a[i]==2) res[2]++;
			if(a[n]==2&&a[i]==1) res[1]++;
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<' ';
		return 0;
	}
	if(!f){
		a[n+1]=m+1;
		for(int i=1;i<=n;i++) res[a[i]]=i;
		for(int i=1;i<=n;i++) cout<<res[i]<<' ';
		return 0;
	}
	while(T<=n){
		int cnt=0;
		for(int i=1;i<=m;i++) mp[i]=b[i]=0;
		for(int i=T;i<=n;i++){
			if(!mp[a[i]]) cnt++,mp[a[i]]=cnt,b[cnt]=a[i];
			else if(mp[a[i]]>cnt){
				int o=1,l=cnt;
				for(int j=1;j<=cnt;j++){
					if(!o){
						if(mp[a[i]]>l) mp[a[i]]=0;
						continue;
					}
					if(b[j]==a[i]){
						mp[a[i]]=j;
						l=j; 
						o=0;
					}
				}
				cnt=l;
				if(o) cnt++,mp[a[i]]=cnt,b[cnt]=a[i];
			}
			else{
				int o=-1;
				for(int j=1;j<=cnt;j++){
					if(b[j]==a[i]&&o==-1) o=j;
					if(j>o) if(mp[b[j]]>o) mp[b[j]]=0;
				}	
				cnt=o; 
			}
//			if(T==1) cout<<cnt<<' ';
		}	
//		cout<<'\n';
		int flag=T;
		for(int i=T;i<=n;i++){
			if(a[i]!=a[i+1]){
				flag=i;
				break;
			}
		}
//		if(T==1){
//			for(int i=1;i<=cnt;i++) cout<<b[i]<<' ';
//			cout<<'\n';
//		}
		for(int i=1;i<=cnt;i++)
			res[b[i]]+=flag-T+1;
		T=flag;T++;
	}
	for(int i=1;i<=m;i++) cout<<res[i]<<' ';
	return 0;
}
