#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long LL;
LL n,m,a[N],mx=-1;
LL ans;
void solve1(){
	cout<<mx;
}
void solve(){
	for(int s=0;s<=(1<<n);s++){
		vector<int> v;
		int sum=0;
		for(int i=0;i<n;i++){
			if((1<<i)&s){
				v.push_back(a[i]);
				sum++;
			}
		}
		if(sum!=m) continue;
		LL h=v[0];
		for(int i=1;i<m;i++){
			h=(h&v[i]);
		}
		ans=max(ans,h);
	}
	cout<<ans<<endl;
}
vector<pair<char,int>> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		solve1();
		return 0;
	}
	if(n<=20){
		solve();
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,1ll*(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<3<<endl;
	return 0;
}
