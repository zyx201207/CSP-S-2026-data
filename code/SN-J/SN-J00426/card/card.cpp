#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
stack<long long>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int f=0;
		while(!s.empty()){
			int l=s.top();
			s.pop();
		}
	}
	return 0;
}
