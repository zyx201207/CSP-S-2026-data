#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],d[25],ans=-1;
void df(int k,int y){
	if(k==n+1){
		if(y<m) return;
		int s,fir=0;
		for(int i=1;i<=n;i++){
			if(d[i]){
				if(!fir){
					fir=1;
					s=a[i];
				}else{
					s=s&a[i];
				}
			}
		}
		ans=max(s,ans);
		return;
	}
	if(y>m) return;
	d[k]=0;
	df(k+1,y);
	d[k]=1;
	df(k+1,y+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	df(1,0);
	cout<<ans;
	return 0;
}
