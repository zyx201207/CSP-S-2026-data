#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n,a[maxn];
char c[maxn];
ll ans;
int main(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	//	ios::sync_with_stdio(0);
	//	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		sum+=a[i];
	}
//	if(n%2==0) ml=n/2,mr=n/2+1;
//	else ml=mr=n/2+1;
	int i=1,j=n;
//	l<=r&&l<=ml&&r<=mr
	while(i<j){
		int minl=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=minl;
		a[i]<a[j]? (a[j]-=a[i],i++):(a[i]-=a[j],j--);
	}
	cout<<ans;
	
	
	
	
	return 0;
} 
