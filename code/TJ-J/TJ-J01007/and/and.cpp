#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ma=-1;
bool cmp(long long a,long long b){
	return a>b;
}bool vis[200010]={false};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}if(m==2){
		ma=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}cout<<ma;
		return 0;
	}if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	long long answ=-1;
	for(int f=1;f<=n;f++){
		memset(vis,false,sizeof(vis));
		long long ans=a[f];
		vis[f]=true;
		for(int nu=1;nu<m;nu++){
			long long maxx=-1,wz=0;
			//cout<<"\\"<<ans<<"\n";
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					if(maxx<(ans&a[i])){
						wz=i;
						maxx=ans&a[i];
						//cout<<"    "<<wz<<' '<<maxx<<"\n";
					}
				}
			}ans=maxx;
			//cout<<maxx<<' '<<wz<<"\n";
			vis[wz]=true;
		}answ=max(answ,ans);
	}
	cout<<answ;
	return 0;
} 
