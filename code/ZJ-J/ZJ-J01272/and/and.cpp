#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,x,cnt,len,len1,pos=33,pos1,ans;
int bh[N],bh1[N],f[N][37];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		int cnt=0;
		while(x!=0){
			if(x%2!=0) f[i][cnt]++;
			x>>=1;cnt++;
		}
	}
	for(int i=1;i<=n;i++) bh[++len]=i;
	while(1){
		pos1=-1;
		for(int i=pos-1;i>=0;i--){
			int sl=0;
			for(int j=1;j<=len;j++) sl+=f[bh[j]][i];
			if(sl>=m){
				pos1=i;
				break;
			}
		}
		if(pos1==-1) break;
		pos=pos1;
		ans=ans+(1<<pos);
		len1=0;
		for(int i=1;i<=len;i++)
			if(f[bh[i]][pos]) bh1[++len1]=bh[i];
		for(int i=1;i<=len1;i++) bh[i]=bh1[i];
		len=len1;
	}
	cout<<ans;
	return 0;
}