#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=200010,M=30;
int n,m;
LL a[N],ans;
vector<int> v[M];


void init(){
	for(int i=1;i<=n;i++){
		LL x=a[i];
		LL t=1;
		while(x){
			if(x&1){
				v[t].push_back(a[i]);
			}
			x>>=1;
			t++;
		}
	}
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	init();
	
	for(int i=M-1;i>=0;i--){
		for(LL t:v[i]){
			if(v[i].size()>=m){
				LL x=v[i][v[i].size()-m]&v[i][v[i].size()-1];
				ans=max(ans,x);
			}
		}
	}
	cout<<ans;
	return 0;
}

