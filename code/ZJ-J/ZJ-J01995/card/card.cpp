#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],p1[300005],ps[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p1[a[j]]==0){
				p1[a[j]]=j;
				ps[a[j]]++;
			}
			else{
				for(int k=p1[a[j]];k<j;k++){
					if(p1[a[k]]==0)continue;
					else {
						ps[a[k]]--;
						p1[a[k]]=0;
					}
				}
				p1[a[j]]=j;
				ps[a[j]]++;
			}
		}
		memset(p1,0,sizeof(p1));
	}
	for(int i=1;i<=m;i++){
		cout<<ps[i]<<" ";
	}
	return 0;
}
