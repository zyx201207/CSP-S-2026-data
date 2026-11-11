#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
vector<int> v(0);
int f(int w,vector<int>a){
	int ans=0;
	for(int i=w;i>=1;i--){
		vector<int> b(0);
		int temp=1<<(i-1);
		int cnt=0;
		for(int j=0;j<a.size();j++){
			if(a[j]&temp){
				b.push_back(a[j]);
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=temp;
			ans+=f(i-1,b);
			break;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<f(30,v)<<'\n';
	return  0;
}
