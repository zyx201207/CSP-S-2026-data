#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
long long cnt,l,l1;
struct node{
	long long k;
	char u;
}a[2*N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].k>>a[i].u;
	int o=0,i=1;
	while(i<=n){
		if(n-o<=i) break;
		if(a[i].u!=a[n-o].u)
			cnt+=min(a[i].k,a[n-o].k);
		if(a[i].k>a[n-o].k){
			a[i].k-=a[n-o].k;
			o++;
		}
		else if(a[i].k==a[n-o].k){
			i++;
			o++;
		}
		else{
			a[n-o].k-=a[i].k;
			i++;
		}	
	}
	cout<<cnt;
	return 0;
} //0 1 2 3 4
/*3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
