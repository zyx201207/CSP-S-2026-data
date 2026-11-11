#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	int k[300005]={0},h=0,ans=0;
    	for(int j=i;j<=n;j++){
    		int f=0;
    		for(int l=1;l<=h;l++){
    			if(a[j]==k[l]){
    				f=l;
    				break;
				}
			}
			if(f>0)	h=f-1;
			k[++h]=a[j];
		}
		for(int j=1;j<=h;j++){
			s[k[j]]++;
		}
	//	for(int j=1;j<=h;j++) cout<<s[i]<<" ";
	//	cout<<"\n";
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}

