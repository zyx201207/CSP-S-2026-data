#include<bits/stdc++.h>
using namespace std;
long long sum=0;
const int N=200005;
int n,a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long l=1,r=n;
	while(l<r){
		int t=min(a[l],a[r]);
		if(s[l]!=s[r]){
			sum+=t;
		}
		a[l]-=t;
		a[r]-=t;
		if(a[l]<=0){
			l++;
			a[l]+=a[l-1];
		}
		if(a[r]<=0){
			r--;
			a[r]+=a[r+1];
		}
	}
	cout<<sum;
	return 0;
}
