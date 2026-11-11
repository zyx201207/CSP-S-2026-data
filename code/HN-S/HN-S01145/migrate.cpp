#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,l,r,u,o,num,sum,ans,flag,a[2000010],b[2000010],c[2000010];
int main(  ){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>o>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		b[n]=n;
		for(int i=n-1;i>=1;i--){
			b[i]=b[i+1];
			while(a[b[i]]-a[i]>m) b[i]--;
		}
		flag=0;
		if(o>=11&&o<=12){
			l=b[1],r=b[b[1]];
			if(l!=r&&b[l-1]!=r){
				flag=1;
			}
		}
		ans=0;
		if(flag){
			for(int i=b[1];i<=n;i++){
				if(a[i]-a[i-1]==1&&b[i-1]==i){
					ans+=b[i-1]-i;
				}
				else{
					ans+=b[i-1]-max((long long)i,b[i-2]);
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				k=i,num=0,sum=0;
				while(1){
					c[++num]=k;
					if(num>2){
						if(b[c[num-1]-1]==k){
							sum++;
							if(sum>1) break; 
							if(b[c[num-1]-2]==k){
								break;
							}
							if(num>3&&b[c[num-2]-1]>=c[num-1]-1){
								break;
							}
						}
					}
					if(num>1&&sum==0){
						u=k;
						if(k-2>=i) u=max(u,b[k-2]);
						if(num>2){
							if(b[c[num-1]-1]<k-1||c[num-2]==c[num-1]-1){
								ans+=b[k-1]-u;
							}
						}
						else ans+=b[k-1]-u;
					}
					if(sum){
						ans+=b[k]-b[k-1];
					}
					if(k==b[k]) break;
					k=b[k];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
