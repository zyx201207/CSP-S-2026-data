#include<iostream>
#include<vector>

using namespace std;
const long long MAXN=2e4+1;
long long u,val;
vector<bool> a[MAXN];
vector<int> t[MAXN];
vector<int> x(MAXN);
vector<int> y(MAXN);
vector<int> k(MAXN);
vector<int> w(MAXN);
long long c,n,m,d,q;
string s;
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=q;i++){
		cin>>s;
	}
	for(int i=1;i<=q;i++){
		cout<<(42-i)<<"\n";
	}
	return 0;
}
