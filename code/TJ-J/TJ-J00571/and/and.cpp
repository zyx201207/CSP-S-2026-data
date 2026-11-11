#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
set<int> s;
int ans;
void f(int idx,int num)
{
	if (idx>=m){
		ans=max(ans,num);
		return ;
	}
	for (int i=0;i<n;i++){
		if (s.count(i)) continue;
		if (idx==0) num=a[i];
		s.insert(i);
		f(idx+1,num&a[i]);
		s.erase(i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,0);
	cout<<ans;
	return 0;
}
