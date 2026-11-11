#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
long long sum[500001];
long long st[500001][21];
long long qcst(int l,int r){
	int k=log2(r-l+1);
	//cout<<r<<' '<<l<<' '<<k<<endl;
	return max(st[k][l],st[k][r-(1<<k)+1]);
}long long qcsu(int l,int r){
	return sum[r]-sum[l-1];
}
int h(long long s){
	long long k=0;
	for(int i=1;i<=n-s+1;i++){
		k=s*qcst(i,i+s-1)-qcsu(i,i+s-1);
		//cout<<k<<endl;
		//cout<<i<<' '<<s<<' '<<qcst(i,i+s-1)<<' '<<qcsu(i,i+s-1)<<endl; 
		if(k<=m)return 1;
	} return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		
		sum[i]=sum[i-1]+a[i];
		st[0][i]=a[i];
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n-(1<<i)+1;j++){
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
			//cout<<st[i-1][j]<<' '<<st[0][j]<<' '<<st[i-1][3000]<<' '<<j<<endl; 
		} 
	} 
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(h(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}cout<<l<<endl;
	
	return 0;
}
 

