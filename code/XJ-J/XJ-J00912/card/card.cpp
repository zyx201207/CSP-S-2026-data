#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
string s1,s2;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[1]<<' '<<a[2]<<' '<<a[3];
	return 0;
}