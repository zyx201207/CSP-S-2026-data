#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],last[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],last[a[i]]=i;
    for(int i=1;i<=n;i++){
    	int l=i;
    	while(l<=n){
    		if(l==last[a[l]]) ans[a[l]]++,l++;
    		else l=last[a[l]];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
