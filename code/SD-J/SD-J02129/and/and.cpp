#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
	}
	else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n){
		int now=a[1];
		for(int i=2;i<=n;i++){
			now&=a[i];
		}
		cout<<now;
	}
	else{
		int maxx=-1;
		for(int i=0;i<(1<<n-1);i++){
			int cnt=0,now=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					cnt++;
					now=(now==0?a[j+1]:now&a[j+1]); 
				}
				if(cnt>m) break;
			}
			if(cnt==m) maxx=max(maxx,now);
		}
		cout<<maxx;
	}
	return 0;
}
