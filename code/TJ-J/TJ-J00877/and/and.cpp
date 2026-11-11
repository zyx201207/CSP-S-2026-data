#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	} 
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m=n-1){
		long long ans=0,b=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(b==0){
						b=a[j];
					}else{
						b=b&a[j];
					}
				}
			}
			ans=max(ans,b);
		}
		cout<<ans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<a[n-m+1]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
