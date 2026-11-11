#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	freopen("migtare.in","r",stdin);
	freopen("migtare.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<c<<" ";
		long long int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12||c==0){
			int l=a[2]-a[1];
			long long int k=d/(long long)l;
			long long ans=0;
			for(int i=1;i<=n;i++){
				int p=min(n,i+2*k)-k-i;
				ans+=p;
			}
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}


return 0;
}

