#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],b[N],ans[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int sum=0;
	while(1){
		sum++;
		memset(d,0,sizeof(d));
		for(int i=sum;i<=n;i++){
			d[i]=c[i];
		}
		for(int i=sum;i<=n;i++){
			for(int j=1;j<i;j++){
				if(d[j]==d[i]){
					b[i]=d[i];
					for(int k=1;k<i;k++){
						d[i]=0;
					}
					d[i]=b[i];
				}
			}
		}
		for(int i=sum;i<=n;i++){
			if(d[i]==1){
				ans[1]++;
				continue;
			}else if(d[i]==2){
				ans[2]++;
				continue;
			}else if(d[i]==3){
				ans[3]++;
				continue;
			}
		}
		if(sum==n){
			break;
		}
	}
	cout<<ans[1]-1<<" "<<ans[2]-1<<" "<<ans[3];
	return 0;
} 
