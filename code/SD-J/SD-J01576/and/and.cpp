#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[2];
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i]; 
	}
	cout<<ans;
	return 0;
} 
