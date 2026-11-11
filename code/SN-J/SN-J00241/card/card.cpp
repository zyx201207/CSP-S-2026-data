#include<bits/stdc++.h>
using namespace std;
int a[500005],b[505],c[505],d[505];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			int cnt=0;
			for(int j=i;j<=n;j++){
				if(b[a[j]]==0 or(b[a[j]]!=0 and b[a[j]]>cnt)){
					c[++cnt]=a[j];
					b[a[j]]=cnt;
				}
				else{
					cnt=b[a[j]];
				}
			}
			for(int i=1;i<=cnt;i++){
				d[c[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<d[i]<<" ";
		}
	}
	else{
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<' ';
			}
		}
	}
	return 0;
}
