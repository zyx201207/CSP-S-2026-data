#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
vector<int>a,b;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>x;
        a.push_back(x);
	}
	for(int i=30;i>=0;i--){
        for(auto k:a){
            if(((k>>i)&1)==1) b.push_back(k);
        }
        if(b.size()>=m){
            a=b;
            ans+=(1<<i);
        }
        b.clear();
	}
	cout<<ans;
	return 0;
}
