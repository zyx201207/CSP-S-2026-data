#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
int a[200010];
char c[200010];
int m,n,sumn=0,msum=0,q7_1212=0,ans=0;
int hou[200010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	int op=0;
	for(int i=1;i<=m;i++){
		int x;
		char y;
		cin>>x>>y;
		msum+=x;
		if(i!=1 and y==c[op]){
			a[op]+=x;
		}
		else{
			a[++op]=x;
			c[op]=y;
		}
	}
	n=op;
	//for(int i=1;i<=n;i++)  cout<<a[i]<<' '<<c[i]<<endl;
	int lyj=0,k=1,r=n,rsheng=a[n],ryj=0;
	while(1){
		
		
		if(lyj+a[k]>msum/2){
			if(k==r)  break;
			else{
				ans+=rsheng*(c[r]!=c[k]);
				r--; 
				while(r>k){
					ans+=(c[r]!=c[k])*a[r];
					r--;
				}
				break;
			}
		}
		lyj+=a[k];
		int rsum=0;
		if(a[k]<rsheng)  ans+=(c[k]!=c[r])*a[k],rsheng-=a[k],ryj+=a[k];
		else{
			ans+=(c[k]!=c[r])*rsheng;
			r--;
			rsum+=rsheng;
			ryj+=rsheng;
			while(1){
				if(rsum+a[r]>a[k])  break;
				ans+=(c[k]!=c[r])*a[r];
				rsum+=a[r];
				ryj+=a[r];
				r--;
			}
			if(rsum==a[k])  rsheng=a[r];
			else{
				ans+=(a[k]-rsum)*(c[k]!=c[r]);
				rsheng=a[r]-(a[k]-rsum);
				ryj+=a[k]-rsum;
			}
		}
		//cout<<"No "<<k<<endl;
		//cout<<"lyj: "<<lyj<<endl;
		//cout<<"rsheng :"<<rsheng<<endl;
		//cout<<"ans :"<<ans<<endl;
		//cout<<"____________________________________\n";
		k++;
	}
	cout<<ans;
	return 0;
}

