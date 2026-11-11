#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>5000){
			int now=lower_bound(x+1,x+n+1,x[1]+d)-x-1;
			int now1=lower_bound(x+1,x+n+1,x[n]-d)-x-1;
			if(now==now1) cout<<0;
			else cout<<(n-now)*(n-now-1)/2;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				int b[n+1],c[n+1];
				memset(b,63,sizeof(b));
				for(int i=1;i<=n;i++){
					b[i]=1e9;
					c[i]=0;
				} 
				queue<int>q;
				q.push(i);
				b[i]=0;
				while(!q.empty()){
					int now=q.front();
					q.pop();
					int k=now;
					while(x[k+1]-x[now]<=d&&k<n){
						k++;
						if(b[k]>b[now]+1){
							b[k]=b[now]+1;
							q.push(k);
							c[k]=1;
						}else if(b[k]==b[now]+1){
							c[k]++;
							q.push(k);
						}
					}
					k=now;
					while(x[now]-x[k-1]<=d&&k>1){
						k--;
						if(b[k]>b[now]+1){
							b[k]=b[now]+1;
							q.push(k);
							c[k]=1;
						}else if(b[k]==b[now]+1){
							c[k]++;
							q.push(k);
						}
					}
				}
				for(int i=1;i<=n;i++){
					if(c[i]==2) ans++;
				} 
			}
			cout<<ans/2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}