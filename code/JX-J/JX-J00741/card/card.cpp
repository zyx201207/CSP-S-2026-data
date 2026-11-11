#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],v=0,c[300005],h=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		v=0;
		for(int j=i-1;j<n;j++){
			h=1;
			for(int k=0;k<v;k++){
				if(a[j]==b[k]){
					h=0;
				}
				if(h==0){
					b[k]=-1;
				}
			}
			b[v]=a[j];
			v++;
		}
		for(int k=0;k<v;k++){
			if(b[k]==-1){
				continue;
			}else{
				c[b[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
