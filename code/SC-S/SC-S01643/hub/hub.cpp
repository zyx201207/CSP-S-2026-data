#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int all[10];
vector <int> v;
struct city{
	int lf,rg,id=0;
}a[1000005];
int tree(int st,int ed,int cnt){
	int x=a[st].lf,y=a[st].rg;
	if(x==ed||y==ed) return cnt;
	if(!x) return tree(y,ed,cnt+1);
	if(!y) return tree(x,ed,cnt+1);
	return min(tree(x,ed,cnt+1),tree(y,ed,cnt+1));
}
int tqjl(int st,int ed){
	if(st==ed) return 0;
	if(a[st].lf==ed||a[st].rg==ed) return 1;
	int mina=1e9;
	return min(mina,tree(st,ed,0));
}
int situation(){
	int mom=1,son=1;
	for(int i=1;i<=k;i++) mom*=i;
	for(int i=n;i>=n-k+1;i--) son*=i;
	return son/mom;
}
void hub(int st,int k1){
	for(int i=st;i<=n-(k-v.size());i++){
		v.push_back(i);
		if(v.size()==k){
			int maxa=-1,ans=1e9;
			for(int j=1;j<=n;j++){
				for(int l=0;l<k;l++){
					int d=tqjl(j,v[l]);
					ans=min(ans,d);
				}maxa=max(maxa,ans);
			}all[k1]=maxa;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			int st,ed;
			cin>>st>>ed;
			if(a[st].id==0){
				a[st].lf=ed;
				a[st].id=1;
			}else a[st].rg=ed;
		}for(int d=1;d<=situation();d++){
			for(int j=1;j<=n-k;j++) hub(j,i);
		}
	}
	for(int i=1;i<=t;i++) cout<<all[i]<<"\n";
	return 0;
}