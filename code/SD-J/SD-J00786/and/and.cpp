#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-1;
		for(int i=0;i<n;i++){
			if(a[i]>=maxx) maxx=a[i];
		}
		cout<<maxx;
	}
	else if(m==n){
		int ans;
		for(int i=0;i<n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	else if(m==2){
		int cnt[n*n+5],pos=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				else {
					cnt[pos]=(a[i]&a[j]);
					pos++;
				}
			}
		}
		int maxn=-1;
		for(int i=0;i<=pos;i++){
			if(maxn<cnt[i]) maxn=cnt[i];
		}
		cout<<maxn; 
	}
	return 0;
}
