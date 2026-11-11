#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long a1[200005]={0};
		for(int j=i;j<=n;j++){
			if(a1[j]!=1){
				sum[a[j]]++;
				a1[j]=1;
			}
			else for(int k=j;k>=i;k--){
				if(a[k]==a1[j])break;
				if(sum[a[k]]>0)sum[a[k]]--;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
