#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m;
long long a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long num=0,sum=0,p=0,e=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<m<<a[1];
	return 0;
}
