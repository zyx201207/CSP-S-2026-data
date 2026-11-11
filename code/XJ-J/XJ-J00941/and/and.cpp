#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[31][N],len[31],tight[31]={1},t[N],cnt,ans,cntjc,cnt2=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(t,1,sizeof(t));
	for (int i=0;i<=30;i++){
		if (i>=1){
			tight[i]=tight[i-1]*2;
		}
		for (int j=1;j<=n;j++){
			if (a[j]&tight[i]){
				b[i][++len[i]]=j;
			}
		}
	}
	for (int i=30;i>=0;i--){
		if (len[i]>=m){
			if (cntjc==0){
				cntjc=1;
				ans+=tight[i];
				for (int j=1;j<=len[i];j++){
					t[b[i][j]]=1;
				}
			}
			else{
				cnt=0;
				for (int j=1;j<=len[i];j++){
					if (t[b[i][j]]==cnt2){
						cnt++;
					}
				}
				if (cnt>=m){
					ans+=tight[i];
					for (int j=1;j<=len[i];j++){
						if (t[b[i][j]]==cnt2){
							t[b[i][j]]++;
						}
					}
					cnt2++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
