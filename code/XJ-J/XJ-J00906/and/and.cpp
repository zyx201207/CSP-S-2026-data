#include<bits/stdc++.h>
#include <array>
#include <string>
#include<queue>
using namespace std;
const int N=2e5+10;
int a[N];
string b1,b2,b3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int w;
	long long n;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<min(a[1],min(a[2],a[3]));
	return 0;
}