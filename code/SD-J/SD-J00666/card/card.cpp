#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[300005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			p[j]=a[j];
			for(int k=i;k<j;k++){
				if(p[k]==p[j]){
					for(int z=k;z<j;z++)p[z]=0;
					break;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(p[j]!=0)s[p[j]]++;
			p[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
