#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int s1=0;
	for(int i=1;i<=n;i++){
		int b=0,s=0;
		for(int j=i;j>=1;j--){
			if(b+a[i]-a[j]<=m){
				b+=a[i]-a[j];
				s++;
			}else{
				break;
			}
		}
		if(s1<=s){
			s1=s;
		}else{
			break;
		}
	}
	cout<<s1<<endl;
}
