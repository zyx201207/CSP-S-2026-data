//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//int n,m;
//const int N=5e5+10;
//const int M=3e5+10;
//
//int cnt[N];
//int a[N];
//int kk[N];
//int sum[N];
//int tot;
//struct node{
//	int l;
//	int r;
//}c[N];
//int lst[N];
//bool cmp(node x, node y){
//	if(x.l==y.l) return x.r<y.r;
//	return x.l<y.l;
//} 
//int st[N];
//int diff[N];
//int nxt[N];
//ll fl[N];
//int ans[N]; 
//const ll INF=1e9;
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>n>>m;
//	for(int i=1; i<=n; i++){
//		cin>>a[i];
//		sum[a[i]]++;
//		
//		if(lst[a[i]]){
//			c[++tot].l=lst[a[i]]+1;
//			c[tot].r=i;
//			diff[c[tot].l]++;
//			diff[c[tot].r+1]--;
//			lst[a[i]]=0;
//		}
//		else lst[a[i]]=i;
//	}	
//	
//	for(int i=1; i<=n; i++){
//		diff[i]+=diff[i-1];
//		if(diff[i]){
//			sum[a[i]]--;
//		}
//	}
//	for(int i=1; i<=m; i++){
//		if(sum[i]==0){
//			fl[i]=1;
//		}
//		else{
//			fl[i]=INF;
//		}
//		ans[i]=n;
//		cout<<sum[i]<<" ";
//	}
//	cout<<"\n";
//	sort(c+1,c+1+tot,cmp);
//	for(int i=1; i<=tot; i++){
//		kk[i]=c[i].l;
//		cout<<c[i].l<<" "<<c[i].r<<"\n";
//	}
//	for(int i=1; i<=n; i++){
//		int pos=lower_bound(kk+1,kk+1+tot,i)-kk;
//		nxt[i]=pos;
//	}
//	int k=1;
//
//	for(int i=1,j=1; i<=n; i++){
//		sum[a[i-1]]--;
//		if(sum[a[i-1]]==0) fl[a[i-1]]=i;
//		if(i-1>=c[k].l&&k<=tot){
//			for(int t=c[k].l; t<=c[k].r; t++){
//				sum[a[t]]++;
//				if(sum[a[t]]==1){
//					ans[a[t]]=ans[a[t]]-(t-fl[a[t]]);
//					fl[a[t]]==INF;
//				}	
//			}
//			cout<<k<<" ";
//			cout<<c[k].r<<"\n";
//
//			k=nxt[c[k].r];
//		}	
//	}
//	for(int i=1; i<=m; i++){
//		if(fl[i]!=INF){
//			ans[i]=ans[i]-(n-fl[i]+1);
//		}
//	}
//	for(int i=1; i<=m; i++){
//		cout<<ans[i]<<" ";
//	}
//	return 0;
//} 
///*
//4 3
//1 2 1 3
//*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
ll lst[N];
ll pre[5010][3010];
ll ans[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		for(int j=1; j<=m; j++){
			pre[i][j]=pre[i-1][j];
		}
		pre[i][a[i]]++;
	}
	for(int j=1; j<=n; j++){
		ll sum[3010]={0};
		ll lst[3010]={0};
		bool vis[3010]={0};
		for(int i=j; i<=n; i++){
		    sum[a[i]]++;
			if(lst[a[i]]&&vis[lst[a[i]]]==0){
				
				for(int k=lst[a[i]]; k<=i-1; k++){
					if(!vis[k]){
						vis[k]=1;
						sum[a[k]]--;			
					}
				}
		
			}
			lst[a[i]]=i;
		}
		
		for(int k=1; k<=m; k++){
			if(sum[k]){
				ans[k]++;
			}
		}
		
	} 
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}
