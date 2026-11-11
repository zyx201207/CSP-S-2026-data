#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[2][N],cnt[2],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[0][i]=a[i];
	cnt[0]=n;
	for(int k=29;k>=0;k--){
		int j1=(k+1)&1,j2=k&1;
		int sum=0;
		for(int i=1;i<=cnt[j1];i++)
			if((b[j1][i]>>k)&1) sum++;
		if(sum>=m){
			cnt[j2]=0;
			for(int i=1;i<=cnt[j1];i++){
				if((b[j1][i]>>k)&1) b[j2][++cnt[j2]]=b[j1][i];
			} ans+=(1<<k);
		}
		else{
			for(int i=1;i<=cnt[j1];i++){
				b[j2][i]=b[j1][i];	
			} cnt[j2]=cnt[j1];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
