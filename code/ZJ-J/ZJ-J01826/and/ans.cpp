#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],cnt[40][200100],p[200100],ans,l=1,r,num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;x>0;j++){
			cnt[j][i]=cnt[j][i-1]+(x&1);
			x=x>>1;
			num=max(num,j);
		}
	}
	r=n;
	for(int i=num;i>=1;i--){
		ans=ans<<1;
		int f=0,x=l;
		while(cnt[i][x]==0)x++;
		for(int j=x;cnt[i][j]!=0&&j<=r;j++){
			if(p[j]!=-1)f+=cnt[i][j]-cnt[i][j-1];
		}
		if(f<m)continue;
		else{
			ans+=1;
			for(int j=x;cnt[i][j]!=0&&j<=r;j++){
				if(cnt[i][j]-cnt[i][j-1]==0)p[j]=-1;
				if(cnt[i][j+1]==0)r=min(j,r);
			}
			l=x;
		}
	}
	cout<<ans;
	return 0;
}
