#include<bits/stdc++.h>
const int slen=5e5+10;
using namespace std;
int a[slen],b[slen],c[slen],d[slen];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		int j=1;
		for(int i=1;i<=m;i++) b[i]=0;
		for(int i=o;i<=n;i++){
			if(b[a[i]]!=0){
				for(int x=b[a[i]]+1;x<=j;x++){
					b[c[x]]=0;
				}
				j=b[a[i]];
				c[j++]=a[i];
			}
			else{
				b[a[i]]=j;
				c[j++]=a[i];
			}
		}
		for(int i=1;i<j;i++) {
			d[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
