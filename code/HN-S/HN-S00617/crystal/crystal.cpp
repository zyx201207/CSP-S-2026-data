#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxl=LONG_LONG_MIN;
int a[500005];
int s[500005];
int num=0;
bool flaga=1;
bool flagb=1;
int b;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	s[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flaga=0;
	}
	if(n>=2) b=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=b){
			flagb=0;
			break;
		}
	if(flaga==1){
		for(int i=1;i<=n;i++){
			num+=i;
			if(num>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(flagb==1){
		for(int i=1;i<=n;i++){
			num+=(i*b);
			if(num>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]*(j-i+1)-(s[j]-s[i-1])<=m){
				maxl=max(maxl,j-i+1);
//				cout<<"maxl = "<<maxl<<"    j - i + 1 = "<<j-i+1; 
//				cout<<"    j = "<<j<<"    i = "<<i<<'\n';
			}
		}
	}
	cout<<maxl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

