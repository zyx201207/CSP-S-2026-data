#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
long long a[N],f[N],num=0,num2=0;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),num=max(num,a[i]),num2=num2^a[i];
	if(m==2){
		long long ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<num;
		return 0;
	}
	f[0]=1;
	for(int i=0;i<30;i++) f[0]=f[0]*2;
	f[0]-=1;
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			if(a[i]!=0) f[j]=max(f[j],f[j-1]&a[i]);
			//cout<<f[j]<<' ';
		}
		//cout<<endl;
	}
	cout<<f[m];
	return 0;
}
