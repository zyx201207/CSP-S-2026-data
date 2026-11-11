#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],d[300005];
bool ok=1,ook=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) ok=0;
		if(a[i]>a[i-1]) ook=0;
	}
	if(ok||ook){
		for(int i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
	}
	else{
		for(int i=1;i<=m;i++){
			int st;
			bool ff=0;
			for(int j=1;j<=n;j++){
				if(a[j]==i){
					if(ff){
						for(int k=st+1;k<j;k++){
							c[k]=max(c[k],st);
						}
					}
					else{
						ff=1;
					}
					st=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(c[j]<i){
					if(d[a[j]]!=i){
						b[a[j]]++;
					}
					d[a[j]]=i;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}