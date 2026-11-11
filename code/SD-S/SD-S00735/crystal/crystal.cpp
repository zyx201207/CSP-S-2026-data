#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i < n; i++){
		b[i] = a[i + 1] - a[i];
	}
	int i = 1,j = 1,ans = 1,cnt = 1,k = 0;
	while(j<n){
		if(k+cnt*b[j]<=m){
			k += cnt*b[j];
			cnt++;
			j++;
		}else{
			ans = max(ans,cnt);
			cnt = 1;
			k = 0;
		}
	}
	cout<<max(ans,cnt)<<endl;
	return 0;
}

