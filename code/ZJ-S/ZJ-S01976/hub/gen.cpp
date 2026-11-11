#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
void solve(int n){
	cout<<n<<" "<<n<<"\n";
	for(int i=2;i<=n;i++) cout<<rd()%(i-1)+1<<" "<<i<<"\n";
}
int main(){
	freopen("test.in","w",stdout);
	cout<<0<<" "<<3<<"\n";
	solve(4000),solve(4000),solve(2000);
	return 0;
}