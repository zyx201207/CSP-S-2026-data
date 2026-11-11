#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
long long n,m;
const int N=5e5+10;
long long a[N];
long long maxx=-0x3f3f3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int qd=1;
	for(int i=1;i<=n;i++){
		long long k=m;
		long long num=0;
		for(int j=i;j>=qd;j--){
			if(k>=a[i]-a[j]){
				k-=(a[i]-a[j]);
				num++;
			}
			else{
				qd=j;
				break;
			}
		}
		maxx=max(maxx,num);
	}
	cout<<maxx;
}