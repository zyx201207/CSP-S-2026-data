#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],step[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	step[0]=0;
	step[1]=0;
	for(int i=2;i<=n;i++){
		step[i]=step[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(step[i]<=m){
			ans=i;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}