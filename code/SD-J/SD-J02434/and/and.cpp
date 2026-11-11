#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int MAX=1073741823;
int n,m,a[N],ans,cnt,maxs=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(a[i]&a[j]));
				}
			}
		}
		cout<<ans;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			cnt=MAX;
			for(int j=1;j<=n;j++){
				if(i!=j){
					cnt=cnt&a[j];
				}	
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else if(n==m){
		cnt=MAX;
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else{
		sort(a+1,a+n+1);
		ans=MAX;
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}

