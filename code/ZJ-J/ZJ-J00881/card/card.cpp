#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int b[500001];
bool vis[500001];
long long sum[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}else if(m==2){
		for(int j=1;j<=n;j++){
			bool flag1=0,flag2=0;
			for(int i=j;i<=n;i++){
				if(a[i]==1){
					flag1^=1;
				}else{
					flag2^=1;
				}
			}
			if(flag1) sum[1]++;
			if(flag2) sum[2]++;
		}
		cout<<sum[1]<<' '<<sum[2];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=i;k<=j-1;k++){
				if(b[k]==b[j]){
					flag=1;
					b[k]=-1;
				}
				if(flag==1){
					b[k]=-1;
				}
			}
		}
		for(int k=i;k<=n;k++){
			if(b[k]!=-1&&vis[b[k]]==0){
				vis[b[k]]=1;
				sum[b[k]]++;
			}
		}
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}