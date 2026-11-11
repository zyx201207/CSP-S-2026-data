#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
struct node{
	char c;
	int b=0,e=0;
}a[N];
int n;
int solve1(int bx){//begin
	int ans=-1,l=1,r=n;
	while(l<=r){
		int mid=(r+l)/2;
		//cout<<l<<" "<<r<<" ";
		if(a[mid].e>=bx){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int solve2(int ex){
	int ans=-1,l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].e>=ex)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].b=a[i-1].e+1;
		a[i].e=a[i].b+x-1;
		cin>>a[i].c;
		//cout<<a[i].b<<" "<<a[i].e<<" "<<a[i].c<<"\n";
	}
	int p=a[n].e;
	int ans=0;
	int pos=-1;
	for(int i=1;i<=n;i++){
		int bx=p+1-a[i].e,ex=p+1-a[i].b;
		if(ex<=p/2+1)continue;
		//cout<<ex<<"\n";
		int b=solve1(bx),e=solve2(ex);
		for(int j=b;j<=e;j++){ 
			if(a[j].c==a[i].c)continue;
			if(j==b){
				ans+=min(ex,a[j].e)-bx+1;
			}else if(j==e){
				ans+=ex-max(a[j].b,bx)+1;
			}else{
				ans+=min(ex,a[j].e)-max(a[j].b,bx)+1;
			}
			a[j].e=bx-1;
			//cout<<a[j].e<<" "<<bx<<"\n";
			//cout<<ans<<" ";
		}
	}
	cout<<ans;
	/*
	for(int i=pos+1;i<=n;i++){
		int ex=p+1-a[i].b;
		if(a[i].e<=ex&&a[i].c!=a[pos].c){
			ans+=a[i].e-a[i].b+1;
		}else if(ex>=a[i].b){
			ans+=ex-a[i].b+1;
		}
	}
	*/
	return 0;
} 
/*
2
1 a
4 b

3
1 b
1 b
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c

2
2 a
3 a
*/
