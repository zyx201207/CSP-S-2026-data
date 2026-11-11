#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],res;
queue<pair<int,int>> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int pow=m,cr=a[n],id=n,sum=1;
	for(int i=n-1;i>0;i--){
		q.push({a[i],i});
		if(pow>=cr-a[i]){
			sum++;
			pow-=cr-a[i];
			continue;
		}
		res=max(res,sum);
		//fan hiu
		while(pow<cr-a[i]){
			while(q.front().first==cr){
				q.pop();
			}
			auto ne=q.front();
			sum-=id-ne.second;
			pow+=sum*(cr-ne.first);
			cr=ne.first;
			id=ne.second;
		}
		sum++;
		pow-=cr-a[i];
	}
	res=max(res,sum);
	cout<<res;
	return 0;
}
