#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int a[200005],cnt[200005],t[200005],ttt;
map<int,int>v[200005];
bool b[200005];
int n,m,ans,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],tt=0;
		while(x){
			if(x%2==1)cnt[tt]++;
			else{
				v[tt][++t[tt]]=i;
			}
			tt++;
			x/=2;
		}
		maxx=max(maxx,tt-1);
	}
	for(int i=maxx;i>=0;i--){
		if(cnt[i]>=m){
			ttt=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		
		if(a[i]<(1<<ttt))v[ttt][++t[ttt]]=i;
	}
	for(int i=ttt;i>=0;i--){
		if(cnt[i]<m){
			continue;
		}
		ans+=pow(2,i);
		for(int j=1;j<=t[i];j++){
			int x=v[i][j];
			if(b[x])continue;
			b[x]=1;
			x=a[x];
			int tt=0;
			while(x){
				if(x%2==1)cnt[tt]--;
				tt++;
				x/=2;
			}
		}
	}
	cout<<ans;
	return 0;
} 
