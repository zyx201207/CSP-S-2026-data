#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=500005;
int a[N];
int ans;
void solveA() {
	for(int i=2; i<n; i++) {
		int last=m;
		int t1=i,t2=i;
		while((t1>1&&last>=(a[i]-a[t1-1]))||(t2<n&&last>=(a[t2+1]-a[i]))) {
			if(t1==1&&t2==n)break;
			else if(t1==1)t2++,last-=(a[t2]-a[i]);
			else if(t2==n)t1--,last-=(a[i]-a[t1]);
			else if(a[i]-a[t1-1]<a[t2+1]-a[i]&&t1>1)t1--,last-=(a[i]-a[t1]);
			else if(a[i]-a[t1-1]>a[t2+1]-a[i]&&t2<n)t2++,last-=(a[t2]-a[i]);
			else {
				t1--;
				last-=(a[i]-a[t1]);
			}
		}
		ans=max(ans,t2-t1+1);
	}
}
void solveB() {
	int i=a[(n+1)/2];
	int t1=i,t2=i;
	while((t1>1&&m>=(a[i]-a[t1-1]))||(t2<n&&m>=(a[t2+1]-a[i]))) {
		if(t1==1&&t2==n)break;
		else if(t1==1)t2++,m-=(a[t2]-a[i]);
		else if(t2==n)t1--,m-=(a[i]-a[t1]);
		else if(a[i]-a[t1-1]<a[t2+1]-a[i]&&t1>1)t1--,m-=(a[i]-a[t1]);
		else if(a[i]-a[t1-1]>a[t2+1]-a[i]&&t2<n)t2++,m-=(a[t2]-a[i]);
		else {
			t2++;
			m-=(a[t2]-a[i]);
		}
	}
	ans=(t2-t1)/(a[2]-a[1])+1;
}
void solveC(){
	
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++)if(a[2]-a[1]!=a[i]-a[i-1])flag=false;
	if(n<=5000)solveA();
	else if(flag)solveB();
	else solveC();
	cout<<ans;
}
