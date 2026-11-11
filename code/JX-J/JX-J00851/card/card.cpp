#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10101],b[10101],ct;
unordered_map<int,int> m1,m2;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);ct=0;
		for(int j=i;j<=n;j++){
			int t=-1;
			for(int k=0;k<ct;k++){
				if(b[k]==a[j]){
					t=k;
					break;
				}
			}
			if(t!=-1){
				for(int k=t;k<=ct;k++){
					b[i]=0;
				}
				ct=t;
			}
			b[ct++]=a[j];
		}
		m2.clear();
		for(int i=0;i<ct;i++) m2[b[i]]=1;
		for(auto p:m2){
			m1[p.first]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<m1[i]<<" ";
	return 0;
}
