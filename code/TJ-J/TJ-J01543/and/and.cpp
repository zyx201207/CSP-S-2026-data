#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);		
	}
	long long cnt=0;
	for(int j=30;j>=0;j--){
		vector<int>b;
		for(auto i:a){
			if((i>>j)&1){
				b.push_back(i); 
			}
		}
		if(b.size()>=m){
			a=b;
			cnt+=(1<<j);
		}
	}
	cout<<cnt;
	return 0;
}
//zsy 
