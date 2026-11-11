#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,top=30,sum;
bool p[200005][33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int>ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans.push_back(i);
		int tot=0;
		while(a[i]){
			p[i][tot]=a[i]%2;
			a[i]/=2;
			++tot;
		}
	}
	while(top>=0){
		int tot=0,si=ans.size();
		vector<int>s;
		for(int i=0;i<si;i++){
			if(p[ans[i]][top]){
				s.push_back(ans[i]);
			}
		}
		if((int)s.size()>=m){
			ans=s;
			sum+=(1LL<<top);
		}
		top--;
	}
	cout<<sum;
	return 0;
}