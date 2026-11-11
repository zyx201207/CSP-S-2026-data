#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],t,b[M],c[N],ans[M],mx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=mx;j++) b[j]=-1;
		t=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=-1){
				while(t>b[a[j]]){
					b[c[t]]=-1;
					t--;
				}
			}
			else{
				c[++t]=a[j];
				b[a[j]]=t;
			}
		}
		for(int j=1;j<=t;j++) ans[c[j]]++;
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}
