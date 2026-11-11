#include <iostream>
#include <vector>
#include <stack>
#define int long long
using namespace std;
int n,m,a[200002],cnt=0,pw[32]={1},ans=0;
bool bn[200002][32];
stack <int> st;
vector <int> v[32];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<31;i++) pw[i]=pw[i-1]*2;
	for (int i=1;i<=n;i++){
		v[0].push_back(i);
		cin >> a[i];
		int x=a[i];
		while (x){
			st.push(x%2);
			x/=2;
		}
		int tot=st.size()-1;
		while (!st.empty()){
			if (st.top()) bn[i][tot]=1;
			tot--;
			st.pop();
		}
	}
	for (int i=30;i>-1;i--){
		int tot=0;
		for (auto j:v[cnt]){
			if (bn[j][i]) tot++;
		}
		if (tot>=m){
			ans+=pw[i];
			for (auto j:v[cnt]){
				if (bn[j][i]) v[cnt+1].push_back(j);
			}
			cnt++;
		}
	}
	cout << ans;
	return 0;
}
