#include<bits/stdc++.h>
using namespace std;
int a[100005][55];
bool dp;
int c[55],sum;
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n,m,b[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int j=1;
		while(b[i]){
			if(b[i]==0)break;
			a[i][j]=b[i]%2;
			b[i]/=2;
			j++;
		}
	}
	for(int i=n;i>=1;i--){
		int o=m-1,dp;
		for(int j=i-1;j>=1;j--){
			if(o==0)
			break;
			for(int k=1;k<=35;k++){
				if(a[i][k]==a[j][k])c[k]=a[i][k];
				else c[k]=0;
			}
			o--;
		}for(int k=35;k>1;k--){
				if(c[k]!=0||dp==1){
				c[k-1]+=c[k]*2;
				dp=1;
				}
			}
			if(sum<=c[1])sum=c[1];
	}
	cout<<sum;
	return 0;
}
