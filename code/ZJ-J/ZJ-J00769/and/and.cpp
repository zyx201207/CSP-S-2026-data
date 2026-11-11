#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f;
int a[N],n,m,flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			flag=0;
		}
	}
	if(m==1){
		int ans=-inf;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		int ans=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(flag==1){
		int b[5];
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=4;i>=1;i--){
			if(b[i]>=m){
				cout<<i;
				return 0;
			}
		}if(b[1]+b[2]+b[3]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
