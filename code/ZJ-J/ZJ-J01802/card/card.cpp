#include<bits/stdc++.h>
using namespace std;
long long int n,m,a;
long long int l[300005],t[500005],b[500005];
long long int ans[300005];
bool s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int o=1;o<=n;o++){
		long long int j=1;
		memset(l,0,300005);
		memset(s,0,300005);
		for(int i=o;i<=n;i++){
			a=b[i];
			if(j==1){
				t[j]=a;
				l[a]=j;
				s[a]=1;
				j++;
			}
			else{
				if(l[a]==0){
					l[a]=j;
					t[j]=a;
					j+=1;
					s[a]=1;
				}
				else{
					for(int x=l[a]+1;x<j;x++) s[t[x]]=0;
					j=l[a]+1;
					s[a]=1;
				}
			}
		}
		for(int x=1;x<=m;x++){
			if(s[x]==1) ans[x]+=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	
	return 0;
}
