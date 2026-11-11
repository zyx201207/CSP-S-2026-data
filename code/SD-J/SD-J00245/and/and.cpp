#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	long long maxa=-1;
	long long mina=100000000000000000;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxa)maxa=a[i];
		if(a[i]<mina)mina=a[i];
	}
	if(m==1){
		cout<<maxa;
	}
	else if(m==(n-1)){

		int k=0;
		int ans;
			for(int j=1;j<n;j++){
				int b,k1;
				if(j!=0)
				b=a[0],k1=a[0];
				for(int q=1;q<n;q++){
					if(q!=j){
						b=b&a[q];
						k1=a[q]&k1;
					}
				}
				ans=max(b,k1);
				k=max(k,ans);
			}
	
		cout<<k;
	}
	else if(m==n){
		int k=a[0];
		//cout<<k&&k;
		for(int i=1;i<n;i++){
			int bn=a[i];
		k=(k&bn);
		//cout<<a[i]<<" "<<k;
		}
		cout<<k;
	}
	else if(m==2){
		int ans=0,b,k;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				b=a[i]&a[j];
				k=a[j]&a[i];
				//cout<<b<<" "<<k<<"\n";
			}
			int c=max(b,k);
			ans=max(ans,c);
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
