#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum,ans;
struct ddd{
	int b;
	char c;
};
ddd a[200005];
int ef(int i,int w){
	int mdl=-1,l=i,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].b>=w){
			mdl=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return mdl;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	a[0].b=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		cin>>a[i].c;
		sum+=a[i].b;
		a[i].b+=a[i-1].b;
	}
	for(int i=1;i<=n;i++){
		bool t=0;
//		int u=ef(i,n,sum-a[i].b+1);
//		if(u==-1) break;
//		else{
//			int y=a[u].b;
//			if(y>=sum-a[i-1].b){
//				if(a[u].c!=a[i].c) ans+=(a[i].b-a[i-1].b);
//			}
//			else{
//				if(a[u].c!=a[i].c) 
//			}
//		}
		if(a[i].b>=sum/2){
			a[i].b=sum/2;
			t=1;
		}
		int u=a[i-1].b+1;
		while(1){
			int y=ef(i,sum-u+1);
			int p=sum-a[y-1].b;
			if(a[i].b<=p){
				if(a[i].c!=a[y].c) ans+=(a[i].b-u+1);
				break;
			}
			else{
				if(a[i].c!=a[y].c) ans+=(p-u+1);
				u=p+1;
			}
		}
		if(t) break;
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
