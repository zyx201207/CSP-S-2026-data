#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
int a[N]={};
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll ans=0,maxm=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	for(int i=1;i<n;i++){
		ans=1;
		int bei=m;
		for(int j=i-1;j>=0;j--){
			if(bei>=a[i]-a[j]){
				bei=bei-(a[i]-a[j]);
				ans++;
			}else{
				break;
			}
		}
		maxm=max(maxm,ans);
	}
	cout<<maxm;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
