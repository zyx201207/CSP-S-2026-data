#include <bits/stdc++.h>
#define maxn
#define ll long long
using namespace std;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	ll n,d;
	bool check;
	while(t--){
		cin>>n>>d;
		vector<ll> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		int cnt=0;
		for(int i=0;i<n;i++){
//			check=false;
			for(int j=i+2;j<n;j++){
//				cout<<j<<" "<<i<<"\n";
				int bg=max(a[i+1]-a[i],a[j]-a[i+1]);
				int bm=max(a[i+2]-a[i],a[j]-a[i+2]);
				if(a[j]-a[i]>d&&bg<=d&&bm<=d&&bg>=d/2&&bm>=d/2&&j-i+1==4){//&&j-i+1==4
					cnt++;
//					cout<<a[j]<<" "<<a[i]<<"\n";
					//check=true;
					break;
				}
				/*
				if(a[i+2]-a[i]<=d&&a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d){
					cnt++;
					cout<<a[j]<<" "<<a[i]<<"\n";
					check=true;
				}
				if(check){
					break;
				}
				*/
			}
			/*
			if(abs(a[0]-a[i])>dis){
				for(int j=i-1;j>=0;j--){
					if(abs(a[0]-a[i])==dis){
						cnt++;
						break;
					}
				}
			}else if(abs(a[0]-a[i])==dis){
				cnt++;
			}
			*/
		}
		/*
		if(cnt%2==0){
			cout<<cnt/2;
		}else{
			cout<<cnt/2+1;
		}
		*/
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/
