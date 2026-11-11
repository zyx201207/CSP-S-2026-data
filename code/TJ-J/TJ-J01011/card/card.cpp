#include<bits/stdc++.h>
using namespace std;
int b[30005],a[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q[50005]={0},h=1;
		bool f[30005]={0};
		for(int j=i;j<=n;j++){
			for(int k=1;k<=h;k++){
				if(q[k]==a[j]){
					if(j<=k)
						for(int l=j;l<k;l++){
							q[l]=-1;
						}
					else
						for(int l=k;l<j;l++){
							q[l]=-1;
						}
				}
			}
			q[h++]=a[j];
		}
		for(int j=1;j<=h;j++){
			if(q[j]!=0&&q[j]!=-1&&f[q[j]]==0){
				b[q[j]]++;
				f[q[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
