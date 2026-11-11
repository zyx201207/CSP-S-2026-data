#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool b[N][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			b[i][j]=a[i]&(1<<j);
		}
	}
	vector<int>v;
	int highest;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=b[i][j];
		}
		if(cnt>=m){
			highest=j;
			for(int i=1;i<=n;i++){
				if(b[i][j])v.push_back(i);
			}
			break;
		}
	}
	int ans=0;
	for(int j=highest;j>=0;j--){
		vector<int>q;
		for(auto i:v){
			if(b[i][j]){
				q.push_back(i);
			}
		}
		if(q.size()>=m){
			swap(v,q);
			ans+=(1<<j);
		}
	}cout<<ans;
	return 0;
}
