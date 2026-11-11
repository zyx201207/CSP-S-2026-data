#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,s;
long long m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1,j=2;j<=n;j++){
		while((b[j]=(j-i)*(a[j]-a[j-1])+b[j-1])>m){
			b[j-1]-=a[j-1]-a[i++];
		}
		s=max(s,j-i+1);
	}
	cout<<s;
	return 0;
}