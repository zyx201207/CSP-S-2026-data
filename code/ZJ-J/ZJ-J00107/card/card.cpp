#include<iostream>
#include<stack>
using namespace std;
int a[500005];
bool f[300005];
int tong[300005];
stack <int> s;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(f[a[j]]==1) {
				while(s.top()!=a[j]) {
					int x=s.top();
					s.pop();
					f[x]=0;
				}
				s.pop();
			}
			s.push(a[j]);
			f[a[j]]=1;
		}
		while(!s.empty()) {
			s.pop();
		}
		for(int j=1; j<=m; j++) {
			if(f[j]==1) {
				tong[j]++;
				f[j]=0;
			}
		}
	}
	for(int j=1; j<=m; j++) {
		cout<<tong[j]<<" ";
	}
	return 0;
}
