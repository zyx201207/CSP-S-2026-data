#include<bits/stdc++.h>
using namespace std;
int c,t,n,x,y,ans;
vector<int> e[1000010];
bool check(int x){
	return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int l=0,r=1e9;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		cout<<ans;
	}
	return 0;
}
/*[(^v^)]*/
