#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210000],sum[120000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int a1[120000]={0};
		int s[210000]={0};
		for(int j=i;j<=n;j++){
			if(a1[a[j]]==0) {
				s[j]=a[j];
				a1[a[j]]=j;
			}
			else {
				for(int k=a1[a[j]];k<j;k++){
					a1[s[k]]=0;
					s[k]=0;
				}
				s[j]=a[j];
				a1[a[j]]=j;
			}	
		}
		for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(s[j]==i){
						sum[i]++;
						break;
					}
				}
			}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
