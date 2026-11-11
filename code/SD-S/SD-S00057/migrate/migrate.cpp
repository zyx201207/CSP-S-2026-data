#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n; 
long long d,a[N];
int ok;
void dfs(int x,int y,int sum,int targ){
	if(x==y&&sum==targ){
		ok++;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,sum+1,targ);
		}
	}
}
bool chk(int l,int r){
	int sums=1,lst=0;
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[i-1]>d)return 0;
		if(lst+a[i]-a[i-1]>d){
			lst=0,sums++;
		}
		lst+=a[i]-a[i-1];
	}
	ok=0;
	dfs(l,r,0,sums);
	//cout<<ok<<"?";
	if(ok==2)return 1;
	//if(l==1&&r==4)cout<<sums<<"?";
//	int ttt=0;
//	for(int i=1;i<=sums;i++){
//		int sum2=1,lst2=0;
//		bool chufa=0;
//		for(int j=l+1;j<=r;j++){
//			//if(i==1)cout<<j<<lst2+a[j]-a[j-1]<<" ";
//			if(lst2+a[j]-a[j-1]>d){
//				if(sum2==i){
//					//cout<<"?";
//					chufa=1;
//					j--;
//				}
//				lst2=0,sum2++;
//			}
//			lst2+=a[j]-a[j-1];
//		}
//		//cout<<sum2<<" ";
//		if(chufa&&sum2==sums)ttt++;
//	}
//	if(ttt==1)return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		//	cout<<a[i];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		if(n<=300){
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+3;j<=n;j++){
					ans+=chk(i,j);
				}
			}
			cout<<ans<<endl;
		}
		else if(c==11||c==12){
			long long l=a[2]-a[1];
			long long k=d/l;
			//cout<<d<<" "<<l<<" "<<k<<" ";
			if(k<=1)cout<<0<<endl;
			else{
				cout<<max(0ll,n-2*k+1)<<endl;
			}
		}else if(c==13||c==14){
			int sum=0;
			int id[2];
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					if(sum<2)id[sum]=i;
					sum++;
				}
			}
			if(sum+(n%2)>2)cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
} 
