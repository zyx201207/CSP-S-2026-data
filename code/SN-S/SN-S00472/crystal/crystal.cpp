//SN-S00472 马一涵 陕西省西安中学 
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,a[N],c[N],dist[N],ans=0;
long long m; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++) c[i]=a[i+1]-a[i];
	for(int i=n-2;i>=0;i--){
		int cnt=0,xz=m,h,t=0;
		dist[n]={0};
		dist[i]=c[i];
		for(int j=i;j>0;j--){
			if(c[j]==0) continue;
			else{
				h=c[j];
				t=j;
				break;
			}
		}
		if(!h) h=c[0];
		dist[t]=h;
		for(int j=t-1;j>=0;j--){
			dist[j]=dist[j+1]+c[j];
		}
		for(int j=i;j>=0;j--){
			xz-=dist[j];
			if(xz<0) break;
			else cnt++;
		}
		ans=max(ans,cnt);
	}
	ans++;
	cout<<ans<<"\n";
	return 0;
}
