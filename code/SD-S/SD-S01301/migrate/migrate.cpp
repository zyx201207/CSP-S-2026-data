#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int N=2e6+10;
int n,op,T;
ll d;
ll mp[N];
int yu[N][2];
int ans[N][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>mp[i];
			yu[i][0]=yu[i][1]=0;
			ans[i][0]=ans[i][1]=0;
		}
		int k=0;
		for(int i=1;i<=n-2;i++){
			if(mp[i]+d>=mp[i+1] && mp[i]+d<mp[i+2])k++;
			else{
				yu[i][0]=k;
				k=0;
			}
		}
		for(int i=n;i>=3;i--){
			if(mp[i]-d<=mp[i-1] && mp[i]-d>mp[i-2])k++;
			else{
				yu[i][1]=k;
				k=0;
			}
		}
		
		
		for(int i=2;i<=n-2;i++){
			int mid,l=1,r=i;
			while(l<r){
//				cout<<"1"<<l<<" "<<r<<"\n";
				mid=(l+r)/2;
				if(mp[mid]<mp[i+2]-d) l=mid+1;
				else r=mid;
			}
			int ta=l;
			l=1,r=i;
			while(l<r){
				mid=(l+r)/2;
//				cout<<"2"<<l<<" "<<r<<" "<<mp[mid]<<" "<<mp[i+1]<<" "<<mp[i+1]-d<<"\n";
				if(mp[mid]<mp[i+1]-d) l=mid+1;
				else r=mid;
			}
			int tb=l;
			if(tb<i)ans[i][0]=ta-tb;
			if(ans[i][0]) ans[i][0]+=yu[tb][0];
//		cout<<"-1 =-"<<i<<" "<<ta<<" "<<tb<<"\n";
		}
		for(int i=n-1;i>=3;i--){
			int mid,l=i,r=n;
			while(l<r){
//				cout<<"3"<<l<<" "<<r<<"\n";
				mid=(l+r+1)/2;
				if(mp[mid]<=mp[i-2]+d) l=mid;
				else r=mid-1;
			}
			int ta=l;
			l=i,r=n;
			while(l<r){
//				cout<<"4"<<l<<" "<<r<<"\n";
				mid=(l+r+1)/2;
				if(mp[mid]<=mp[i-1]+d) l=mid;
				else r=mid-1;
			}
			int tb=l;
			if(tb>i)ans[i][1]=tb-ta;
			if(ans[i][1]) ans[i][1]+=yu[tb][1];
//		cout<<"-2 =-"<<ta<<" "<<tb<<"\n";
		}
		ll t=0;
//		for(int i=1;i<=n;i++){
//			cout<<yu[i][0]<<" "<<yu[i][1]<<" "<<ans[i][0]<<" "<<ans[i][1]<<"\n";
//		}
		for(int i=2;i<=n-2;i++){
			t+=ans[i][0]*ans[i+1][1];
		}
		cout<<t<<"\n";
	}
	return 0;
}

