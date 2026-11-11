#include<bits\stdc++.h>

using namespace std;
int c,t;
const int N=2e6+6;
long long n,d,a[N];
bool f,vis[N];
int ff;
bool canmag(int target){
	for(int i=2;i<=ff;i++){
		if(d<abs(a[i]-a[i-1])){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		f=0,ff=-1;
		cin>>n>>d;
		cin>>a[1]>>a[2];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=(a[2]-a[1])){
				f=1;
			}
			if(abs(a[1]-a[i])<=d&&abs(a[n]-a[i])<=d){
				ff=i;
			}
		}
		if(f==0){
			long long gap=a[2]-a[1];
			if(d>2*gap){
				cout<<0;
			}
			else if(d==2*gap){
				cout<<n-d/gap-1;
			}
			else if(d>=gap){
				cout<<0;
			}
			else{
				cout<<0;
			}
		}
		else if(ff!=-1){
			if(canmag(ff)){
				cout<<n-ff+1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<1;
		}
		cout<<"\n";
	}
	return 0;
}
