#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int delta[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	random_shuffle(a+1,a+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		delta[i]=a[i]-a[i-1];
	}
	int l=0,r=n;//[)
	while(l<r){
		int mid=(l+r)/2;
		int t=0,sm=0;
		bool flag=0;
		for(int i=n;i>=2;i--){
			sm+=delta[i];
			t+=sm;
			if(i+mid<=n){
				//cout<<"del "<<delta[i+mid]<<"\n";
				t-=delta[i+mid]*(mid+1);
				sm-=delta[i+mid];
			}
			//cout<<sm<<" "<<t;
			if(i+mid<=n){
				//cout<<":";
				if(t<=m){
					flag=1;
					break;
				}
			}
			//cout<<endl;
		}
		//cout<<l<<" "<<r<<" "<<mid<<" "<<flag<<"\n";
		if(flag){
			if(l==mid)break;
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l+1;
	return 0;
}