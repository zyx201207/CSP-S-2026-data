#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxa=-1,mina=LONG_LONG_MAX;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxa)maxa=a[i];
		if(a[i]<mina)mina=a[i];
	}
	if(n<=20){
		int ans[405],id=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					ans[id]=(a[i]&a[j]);
					id++;
				}
			}
		}
		sort(ans,ans+id,greater<int>());
		for(int i=0,j=0;i<id-1;i++){
			if(ans[i]==ans[i+1])continue;
			j++;
			if(j==m){
				cout<<ans[j];
				break;
			}
		}
	}else if(n<=2000){
		if(m==1){
			cout<<maxa;
		}
		if(m==n){
			long long ans=(a[0]&a[1]);
			for(int i=2;i<n;i++){
				ans=(ans&a[i]);
			}
			cout<<ans;
		}
		if(m==2){
			long long ans=-1;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i!=j){
						if((a[i]&a[j])>ans)ans=(a[i]&a[j]);
					}
				}
			}
			cout<<ans;
		}
	}else{
		if(m==n-1){
			long long ans=LONG_LONG_MAX;
			bool t=0;
			for(int i=0;i<n;i++){
				if(t)ans=(ans&a[i]);
				if(a[i]==mina){
					t=1;
				}else{
					ans=(ans&a[i]);
				}
			}
			cout<<ans;
		}else{
			cout<<mina;
		}
	}
	return 0;
}
