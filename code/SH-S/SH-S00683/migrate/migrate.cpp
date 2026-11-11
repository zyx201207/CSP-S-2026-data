#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000000+5];
signed main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int t,c;
cin>>c>>t;
while(t--){
	int n,m;
	cin>>n>>m;
	bool q=true;
	int k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(i==2)k=a[i]-a[i-1];
		else if(i>2&&q){
			if(a[i]-a[i-1]!=k)q=false;
		}
	}
	if(q){
		if(m>=(a[2]-a[1])*2&&m<=(a[2]-a[1])*2)cout<<n-3<<endl;
		else if(m>=(a[2]-a[1])*3&&m<=(a[2]-a[1])*4)cout<<n-5<<endl;
		else cout<<0<<endl;
	}
	else {
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				queue<int>q1;
				q1.push(i);
				int num=0;
				bool qw=false;
				while(!q1.empty()){
					int w=q1.size();
					for(int qw=1;qw<=w;qw++){
					int q=q1.front();
					q1.pop();
					int k=q+1;
					if(a[k]-a[q]<=m&&k<=j){
						q1.push(k);
						if(k==j)num++;
					}
					if(num>2)break;
				}
				if(num>2)break;
			}
			if(num==2){
				ans++;
			}
		}
	}

		cout<<ans<<endl;
}

}

	return 0;
}
