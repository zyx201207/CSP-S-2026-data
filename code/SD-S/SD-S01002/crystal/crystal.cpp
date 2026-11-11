#include<iostream>
#include<algorithm>
using namespace std;
long long a[500025];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	int st=1,ans=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&a[i]==a[j]) j++;
		j--;
		while(st<=i&&a[i]*(0ll+i-st)-sum>m) sum-=a[st],st++; 
		ans=max(ans,j-st+1);
		sum+=a[i]*(j-i+1);
		i=j;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
