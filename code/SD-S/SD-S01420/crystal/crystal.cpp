#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
}p[500010];
int n,m,a[500010],mx,b[500010],pos,sum[500010];
bool cmp(node l,node r){
	return l.w<r.w;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	/*
	int l=1,r=a[n];
	while(l<=r){
		int mid=l+r>>1;
//		cout<<mid<<"\n";
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	
	cout<<mx;
//	cout<<a[pos-1000]<<" "<<a[pos]<<"\n";
/*
	for(int k=a[pos-1000];k<a[pos];k++){
		for(int i=1;i<=n;i++) p[i]={a[i],k-a[i]};
		sort(p+1,p+1+n,cmp);
		int t=m,cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			if(!p[i].w){
				cnt++;
				continue;
			}
			if(p[i].w<0) continue;
			if(p[i].w<=t){
				t-=p[i].w;
				tot+=p[i].w;
				cnt++;
			}
			else break;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	*/
	if(a[1]-a[2]==a[n-1]-a[n]){
		int x=a[1]-a[2];
		x=abs(x);
		int cnt=1;
		for(int i=1;i<n;i++){
//			cout<<m<<" ";
//			cout<<x*cnt<<"\n";
			if(x*cnt<=m){
				m-=x*cnt;
//				cout<<x<<" "<<cnt<<"\n";
				cnt++;
//				ans++;
			}
			else break;
		}
		cout<<cnt;
		return 0;
	}
	if(a[1]==1 and a[n]==n){
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n;i++){
			if(sum[i]-1<=m) continue;
			else{
				cout<<i-1; 
				break;
			}
		}
		return 0;
	}
	if(a[n]<=1e5){
		for(int k=1;k<=a[n];k++){
			for(int i=1;i<=n;i++) p[i]={a[i],k-a[i]};
			sort(p+1,p+1+n,cmp);
			int t=m,cnt=0,tot=0;
			for(int i=1;i<=n;i++){
				if(!p[i].w){
					cnt++;
					continue;
				}
				if(p[i].w<0) continue;
				if(p[i].w<=t){
					t-=p[i].w;
					tot+=p[i].w;
					cnt++;
				}
				else break;
			}
			mx=max(mx,cnt);
		}
		cout<<mx;
		return 0;
	}
	return 0;
} 
