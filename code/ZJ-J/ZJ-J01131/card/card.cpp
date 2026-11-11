#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300005];
int n,m,z[500005],head,num,x,sum[300005],in[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<m+1;i++){
			a[i]=-1;
		}
		head=0;
	for(int i=k;i<n;i++){
		x=in[i];
		if(a[x]==-1){
			a[x]=head;
			z[head]=x;
			head++;
		}
		else{
			num=a[x];
			for(int j=num+1;j<=head;j++){
				a[z[j]]=-1;
				z[j]=0;
			}
			head=num+1;
		}
		
	}for(int j=0;j<head;j++){
			sum[z[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}