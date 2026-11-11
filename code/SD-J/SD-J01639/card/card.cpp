#include<bits/stdc++.h>
#define st string
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],s[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int k=1;k<=m;k++)
	{			
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j])				
					{
						for(int d=1;d<=j;d++){
							s[d]=a[d];
						}
					}				
				}
			}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
}
