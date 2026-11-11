#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],as[500005],f[300005][2];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]][0]==0){
				f[a[j]][0]=1;
				sum++;
				f[a[j]][1]=sum;
				as[sum]=a[j];
				ans[a[j]]++;
			}else{
				int x=0;
				for(int q=f[a[j]][1];q<=sum;q++){
					f[q][0]=0;
					f[q][1]=0;
					as[q]=0;
					ans[q]--;
					x++;
				}
				f[a[j]][0]=1;
				sum-=x+1;
				f[a[j]][1]=sum;
				ans[a[j]]+=2;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
