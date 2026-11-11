#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],bd[500005],s,ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int b=1,c=0;
			for(int k=1;k<=s;k++){
				if(bd[k]==a[j]){
					c=k;b=0;
					break;
				}
			}
			if(b==0){
				for(int k=c;k<=s;k++){
					bd[k]=0;
				}
				s=c-1;
			}
			s++;
			bd[s]=a[j];
		}
		for(int j=1;j<=s;j++){
			ans[bd[s]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
