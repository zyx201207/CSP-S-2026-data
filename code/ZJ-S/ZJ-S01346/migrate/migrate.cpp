#include<bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
//priority_queue<int>q;
int n,d,ans,a[2000010],vis[200010];
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
	}
	//si`yuan`zu`wen`ti
	//
	for(int i=1;i<=n-3;i++){
		if(abs(a[i]-a[i+1])<=d&&abs(a[i]-a[i+2])<=d&&abs(a[i+3]-a[i+1])<=d&&abs(a[i+3]-a[i+2])<=d&&(abs(a[i]-a[i+3])>d&&abs(a[i]-a[i+3])<=2*d)){
//			cout<<i<<" "<<endl;
			//si`yuan`zu
			vis[i+1]=vis[i+2]=1;
			int l=i,cntl=1;
			while(l>0){
//				cout<<l<<" "<<(abs(a[l-1]-a[l+1])>d)<<" "<<(abs(a[l-1]-a[l])<=d)<<endl;
				if((!(vis[l-1]==1&&vis[l-2]==0))&&abs(a[l-1]-a[l])<=d&&(abs(a[l-1]-a[l+1])>d||i-l>0)){//
					l--;
					cntl++;
				}else{
//					cout<<"?";
					break;
				}
			}
			int r=i+3,cntr=1;
			while(r<=n){
//				cout<<r<<" "<<(abs(a[r+1]-a[r-1])>d)<<" "<<(abs(a[r+1]-a[r])d)<<endl;
				if((!(vis[r+1]==1&&vis[r+2]==0))&&abs(a[r+1]-a[r])<=d&&(abs(a[r+1]-a[r-1])>d||r-i-3>0)){//
					r++;
					cntr++;
					
				}else{
//					cout<<"!";
					break;
				}
			}
//			cout<<l<<" "<<r<<" "<<cntl<<" "<<cntr<<endl;
			ans+=cntl*cntr;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

