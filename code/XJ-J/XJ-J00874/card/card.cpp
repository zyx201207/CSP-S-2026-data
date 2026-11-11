#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[200010]={},s[10005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){	
		cin>>a[i];
		long long b[200010]={};
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(b[k]==a[j]){
					for(int c=k;c<=n;c++)
						b[c]=0;
					
				}
				b[k]=a[j];
			}
		}
		for(int z=1;z<=m;z++){
			for(int l=1;l<=m;l++)
			if(b[l]==z)s[z]++;
		}
	}
	for(int e=1;e<=m;e++){
		cout<<s[e]<<' ';
	}
	return 0;
	
 } 