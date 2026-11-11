#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> a;
vector<int> ans;

// 特殊性质 A  O(n)
void solveA(int n, int m) {
	for(int i=2; i<=n; i++) {
		if(a[i]!=a[i-1]) {
			ans[a[i-1]]=i-1;
		}
	} ans[a[n]]=n;
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	} cout<<endl;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	// 暴力解 O(n^2*m) 
	int n, m;
	cin>>n>>m;
	a.resize(n+1);
	ans.resize(m+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	// 判断是否为特殊性质 A 
	bool flag=true;
	for(int i=1; i<=n; i++) {
		if(a[i-1]>a[i]) {
			flag=false;
			break;
		}
	} if(flag) {
		solveA(n, m);
		return 0;
	}


	for(int i=1; i<=n; i++) {
		// 每个点数最后一次出现的位置 
		vector<int> last(n+1, 0);
		for(int j=i; j<=n; j++) {
			int nl=last[a[j]];
			if(nl>0) {
				for(int k=1; k<=m; k++) {
					if(last[k]>nl) {
						last[k]=0;
					}
				}
			} last[a[j]]=j;
		}
		for(int k=1; k<=m; k++) {
			if(last[k]>0) {
				ans[k]++;
			}
		}
	}

	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	} cout<<endl;
	
	return 0;
}

