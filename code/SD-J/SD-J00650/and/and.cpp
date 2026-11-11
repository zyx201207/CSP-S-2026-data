#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int x,int y){
	return x>y;
}
int tong[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int las=31,ans=0;
	while(las-1>=0){
		for(int i=1;i<=n;i++){
			int cnt=0,v=a[i];
			while(v){
				if(v%2!=0) tong[cnt]++;
				cnt++;
				v/=2; 
			}
		}
		int f=0;
		for(int i=las-1;i>=0;i--){
			if(tong[i]>=m){
				ans+=(1<<i);
				f=1;
				las=i;
				break;
			}
		}
		for(int i=0;i<=30;i++) tong[i]=0;
		if(f==0) break;
		for(int i=1;i<=n;i++){
			if(a[i]<(1<<las)){
				a[i]=0;
				continue;
			}
			int v=a[i],cnt=0;
			while(v){
				if(las==cnt&&v%2==0) a[i]=0;
				cnt++;
				v/=2; 
			}
		}
		//cout<<las<<" ";
	}
	cout<<ans;
	return 0;
}
