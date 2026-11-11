#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200015],d[2000015][30],number[45],ans[45];
void find_(long long x,int j){
	int yu=0,t=1;
	while(x>0){
		yu=x%2;
		d[j][t]=yu;
		if(yu==1){
			number[t]++;
		}
		x/=2;
		t=t+1;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) find_(a[i],i);
	int k=0;
	for(int i=30;i>=1;i--){
		if(number[i]>=m){
			k=i;
			break;
		}
	}
	for(int i=1;i<=k;i++){
		ans[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(d[i][k]==1){
			for(int j=1;j<k;j++){
				if(d[i][j]==0) ans[j]=0;
			}
		}
	}
	long long sum=0;
	for(int i=1;i<=k;i++){
		if(ans[i]==1){
			sum+=pow(2,i-1);
		}
	}
	cout<<sum;
	return 0;
}
