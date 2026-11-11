#include<bits/stdc++.h>
using namespace std;
long long n,m,a[3000],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==2){
		maxx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long jg=a[i]&a[j];
				maxx=max(jg,maxx);
			}
		}
		cout<<maxx;
	}else{
		maxx=a[1];
		for(int i=1;i<n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}
	return 0;
}
