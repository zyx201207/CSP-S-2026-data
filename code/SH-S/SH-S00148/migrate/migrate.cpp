#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d;
int a[2000010];

int find(int x){
	int l=1,r=n,now=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=x-d){
			r=mid-1;
			now=mid;
		}
		else l=mid+1;
	}
	return now;
}

int find2(int x){
	int l=1,r=n,now=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=x+d){
			l=mid+1;
			now=mid;
		}
		else r=mid-1;
	}
	return now;
}

void f1(){
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int dif=a[2]-a[1];
		if(d<=dif)cout<<0<<endl;
		else cout<<max((long long)0,n-2*d/dif+1)<<endl;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11 || c==12){
		f1();
		return 0;
	}
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n-2;i++){
			int l=1,r=1;
			int x=find(a[i+2])-1;
			int k=find(a[i+1]);
			l+=x-k;
			if(k>=i)continue;
			if(a[i+2]-a[k]<=d)continue;
			for(int j=k;j>=1;){
				int y=find(a[j]);
				if(y==j)break;
				if(a[j]-a[y]==d){
					j=y; l++; continue;
				}
				if(j-y>1)break;
				if(a[j+1]-a[j]>d)break;
				if(a[j+2]-a[j]<=d)break;
				l++; j--;
			}
			x=find2(a[i-1])+1;
			k=find2(a[i]);
			r+=k-x;
			if(k<=i+1)continue;
			if(a[k]-a[i-1]<=d)continue;
			for(int j=k;j<=n;){
				int y=find2(a[j]);
				//cout<<y<<" "<<j<<endl;
				if(y==j)break;
				if(a[y]-a[j]==d){
					j=y; r++; continue;
				}
				if(y-j>1)break;
				if(a[j]-a[j-1]>d)break;
				if(a[j]-a[j-2]<=d)break;
				r++;j++;
			}
			//cout<<l<<" "<<r<<endl;
			ans+=l*r;
		}
		cout<<ans<<endl;
	}
}
