#include<bits/stdc++.h>
using namespace std;
long long g[200010],a[200010][40];
long long n,m;
int f[200010],f1[200010];
long long sum;
void change(int x){
	for(int i=30;i>=0;i--){
		if(g[x]>=pow(2,i)){
			a[x][i]=1;
			g[x]-=pow(2,i);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
		change(i);
	}
	memset(f,1,sizeof(f));
	memset(f1,1,sizeof(f1));
	for(int i=30;i>=0;i--){
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(a[j][i]==1&&f[j]==1){
				cnt++;
			}
			else{
				f1[j]=0;
			}
		}
		if(cnt>=m){
			for(long long j=1;j<=n;j++){
				f[j]=f1[j];
			}
			sum+=pow(2,i);
		}
		else {
			for(long long j=1;j<=n;j++){
				f1[j]=f[j];
			}	
		}
	}
	cout<<sum;
	return 0;
}
