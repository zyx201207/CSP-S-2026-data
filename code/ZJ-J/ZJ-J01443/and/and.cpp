#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s=max(s,a);
	}
	std::cout<<s;
}