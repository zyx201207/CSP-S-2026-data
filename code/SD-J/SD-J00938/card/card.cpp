#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s,d[300005],p[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			int f=0;
			for(int k=1;k<i;k++){
				if(f==0&&p[k]==a[j]){
					f=1;
					c=j-1;
				}
				if(f==1){
					p[k]=0;
				}
			}
			p[++c]=a[i];
		}
		for(int j=1;j<=c;j++){
			d[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
