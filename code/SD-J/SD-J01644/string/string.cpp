#include<bits/stdc++.h>
using namespace std;
struct gay{
	int a;
	char b;
} a[200005];
int sum,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}//O(n)
	int l=1,r=n;
	long long sum=0;
	while(l<r){
		int ma=max(a[l].a,a[r].a),mi=min(a[l].a,a[r].a);
		if(a[l].b!=a[r].b){
			sum+=mi;
		}
		if(ma==a[l].a&&ma==a[r].a){
			r--;
			l++;
		}
		else if(ma==a[l].a){
			r--;
			a[l].a-=mi;
		}
		else if(ma==a[r].a){
			l++;
			a[r].a-=mi;
		}
	}//O(n)
	cout<<sum<<'\n';
	return 0;
} 
/*

*/
