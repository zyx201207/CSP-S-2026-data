#include<bits/stdc++.h> 
using namespace std;
long long a[100005];
char c[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ma,cn=0;
	for (int i=1;i<=n;i++){
		ma+=a[i];
	}
	long long k=ma;
	ma=ma/2;
	for(long long i=1;i<=ma;i++){
		long long hj=1,tj=n;
		if (c[hj]!=c[tj]){
			cn++;
		}
		if(i==a[hj]){
			hj++;
		}
		if(i==a[tj]){
			tj--;
		}
		k--;
	}
	cout<<cn;
	return 0;
}
