#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,maxx=-0x3f3f3f3f;
int a[N];
int cnt,Now[N];
int s,ans=-0x3f3f3f3f;
bool cmp(int x,int y){
	return (s-x)<(s-y);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	
	for(int i=1;i<=maxx;i++){
		s=i;
		memset(Now,0,sizeof(Now));
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				Now[++cnt]=a[i];
			}
		}
		sort(Now+1,Now+cnt+1,cmp);
		int all=0,anss=0;
		for(int j=1;j<=cnt;j++){
			if(all+(s-Now[j])>m){
				break;
			}
			else{
				all+=(s-Now[j]);
				anss++;
			}
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
