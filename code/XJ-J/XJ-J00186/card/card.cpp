#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int a[500005];
int flag[300005];
int sum[500005];
int s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		memset(flag,0,sizeof(flag));
		int k=1;
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				s[k]=a[j];
				flag[a[j]]=k;
				k++;
			}else{
				int new_k=flag[a[j]];
				for(int p=new_k;p<=k-1;p++) flag[s[p]]=0;
				k=new_k;
				s[k]=a[j];
				flag[a[j]]=k;
				k++;
			}
		}
		for(int o=1;o<=k-1;o++){
			sum[s[o]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}

