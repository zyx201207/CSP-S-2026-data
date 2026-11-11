#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],k[35];
vector<int>v[35];
vector<int>p[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]>>j&1){
				k[j]++;
				v[j].push_back(a[i]);
			}
		}
	}
	int ans=0;
	int last=31;
	for(int i=30;i>=0;i--){
		
		if(k[i]>=m){
			last=i;
			p[i]=v[i];
			ans|=(1<<i);
			break;
		}
	}
	//for(auto x:p[last])cout<<x;
	for(int i=last-1;i>=0;i--){
		int cnt=0;
		for(auto x:p[last]){
			if((x>>i)&1){
				cnt++;
				p[i].push_back(x);
			}
		}
		if(cnt>=m){
			ans|=(1<<i);
			last=i;
		}
	}
	cout<<ans;
}

