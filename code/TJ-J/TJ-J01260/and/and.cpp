#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int maxx=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i-1]=x;
		maxx=max(maxx,x);
	}
	for(int i=29;i>=0;i--){
		if((1<<i)>maxx) continue;
		
		vector<int> b;
		for(auto j:a)
			if(j&(1<<i)) b.push_back(j);	
		if((int)b.size()>=m){
			a=b;
			if((int)b.size()==m) break;
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	int ans=*a.begin();
	for(int i=1;i<m;i++) ans&=a[i];
	cout<<ans<<endl;
	return 0;
}

