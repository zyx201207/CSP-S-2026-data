#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],k[34],ans,andal=INT_MAX;
int main(){
	//第三题
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		andal=andal&a[i];
	}sort(a+1,a+n+1);
	if(m==2){
		int j=1;
		if(n>=33){
			for(int i=n-32;i<=n;i++){
				k[j]=a[i];
				j++;
			}
		}else{
			for(int i=1;i<=n;i++){
				k[j]=a[i];
				j++;
			}
		}j--;
		for(int i=1;i<=j;i++){
			for(int kl=1;kl<=j;kl++){
				if(i==kl)continue;
				ans=max(ans,k[i]&k[kl]);
			}
		}
	}else if(m==1){
		ans=a[n];
	}else if(m==n){
		ans=andal;
	}else{
		ans=a[n-m+1];
	}
	cout<<ans;
//这个不行，的看看其他的办法，因为0<m<=n，太大了 
	//只考虑前32位 
	return 0;
}
