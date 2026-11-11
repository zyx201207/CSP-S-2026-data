#include <iostream>
using namespace std;
const int maxn=2e5+10;
int n,m;
int a[maxn];
int max_val=0;
bool keep[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		keep[i]=true;
		max_val=max(max_val,a[i]);
	}
	int len=0;
	while(max_val){
		max_val>>=1;
		len++; 
	}
	for(int x=len-1;x>=0;x--){
		int mask=(1<<x);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(keep[i]&&(a[i]&mask)!=0) cnt++;
		}
		if(cnt<m) continue;
		for(int i=1;i<=n;i++){
			if((a[i]&mask)==0) keep[i]=false; 
		}
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(keep[i]){
			cnt++;
			if(ans==0) ans=a[i];
			else ans&=a[i];
			if(cnt==m) break;
		}
	} 
	cout<<ans;
		
} 
