#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN],ans,sumand;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(i==1) sumand=a[i];
    	sumand=sumand&a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	if(m==n){
		int s=a[2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				s=s&a[j];
			}
			ans=max(ans,s);
			s=a[1];
		}
		cout<<ans;
	}
	return 0;
}