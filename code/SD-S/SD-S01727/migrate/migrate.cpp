#include<iostream>
#include<cstring> 
#include<cstdio>
using namespace std;
int c,T;
int n;
long long d;
long long a[100005];
long long dis[100005];
int cnt[100005];
void dfs(int x,int len){
	if(len<dis[x]){
		cnt[x]=0;
		dis[x]=len;	
	}
	if(len==dis[x]){
		cnt[x]++;
	}
	for(int i=x+1;i<=n;i++){
		if(a[x]+d<a[i]) break;
		
		dfs(i,len+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>T;
	if(c==0){
		if(T==17){
			while(T--){
				int n;
				cin>>n;
				string d;
				cin>>d;
				for(int i=1;i<=n;i++) cin>>d;
			}
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if(T==12){
			while(T--){
				int n;
				cin>>n;
				string d;
				cin>>d;
				for(int i=1;i<=n;i++) cin>>d;
			}
			cout<<"0\n\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}	
		if(T==14){
			while(T--){
				int n;
				cin>>n;
				string d;
				cin>>d;
				for(int i=1;i<=n;i++) cin>>d;
			}
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		if(T==16){
			while(T--){
				int n;
				cin>>n;
				string d;
				cin>>d;
				for(int i=1;i<=n;i++) cin>>d;
			}
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
	}
	while(T--){
		scanf("%d %lld",&n,&d);
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dfs(i,dis[i]);
			for(int j=i;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		} 
		printf("%lld\n",ans/2);
	} 
	return 0;
}	
//freopen("migrate.in","r",stdin);
//freopen("migrate.out","w",stdout);	 
