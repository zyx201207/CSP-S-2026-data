#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[5005],b[5005],c[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		int sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		queue<int>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){b[j]=1e18;c[j]=0;
			}
			while(!q.empty())q.pop();
			q.push(i);
			b[i]=0;c[i]=1;
			while(!q.empty()){
				int tp=q.front();q.pop();
				if(c[tp]==2&&tp>i)sum++;
				for(int j=1;j<=n;j++){
					if((abs(a[j]-a[tp])<=m||abs(j-tp)==1)&&b[tp]+1==b[j]){
						c[j]+=c[tp];if(c[j]>3)c[j]=3;
					}
				    if((abs(a[j]-a[tp])<=m||abs(j-tp)==1)&&b[tp]+1<b[j]){
				    	b[j]=b[tp]+1;c[j]=c[tp];q.push(j);
				    }
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}