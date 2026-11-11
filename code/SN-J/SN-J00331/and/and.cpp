#include <bits/stdc++.h>
using namespace std;
vector<long long> nn(200010);
int n,m,sum=2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>nn[i];
	sort(nn.begin(),nn.end(),greater<int>());
	for(int i=0;i<m;i++)sum&=nn[i];
	cout<<sum;
	return 0;
}

