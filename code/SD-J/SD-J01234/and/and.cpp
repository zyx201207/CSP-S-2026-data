#include<iostream>
#include<algorithm>
using namespace std;
int f[105],cnt[200005],x,maxx=1,a[200005],n,l,m;
int v[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int b=a[i],c=0;
		while(b>0){
			c++;
			if((b&1)==1){
				f[c]++;
			}
			b=(b>>1);
		}
		cnt[i]=c;
	}
	for(int i=30;i>0;i--){
		if(f[i]>=m){
			x=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((a[i]>>(x-1))==0){
			v[i]=1;
		}
	}
	for(int i=x-1;i>=1;i--){
		int c=0;
		maxx=(maxx<<1);
		for(int j=1;j<=n;j++){
			if(v[j]==0&&((a[j]>>(i-1))&1)==1){
				c++;
			}
		}
		if(c>=m){
			maxx+=1;
			for(int j=1;j<=n;j++){
				if(v[j]==0&&((a[j]>>(i-1))&1)==0){
					v[j]=1;
				}
			}
		}
	}
	cout<<maxx;
	return 0;
} 
