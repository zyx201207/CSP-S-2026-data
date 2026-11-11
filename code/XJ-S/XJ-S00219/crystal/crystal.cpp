#include<bits/stdc++.h>
using namespace std;
const long long INF = 2e12;
const long long N = 5e5;
long long a[N];
long long cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);	
	int l = 1,mx = 0;;
	for(int i = 2;i<=n;i++){
		cha[i] = (i-l)*(a[i]-a[i-1])+cha[i-1];
		if(cha[i]>m){
			cha[i]-=a[i]-a[l];
			l++;
		}
		mx = max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
} 
