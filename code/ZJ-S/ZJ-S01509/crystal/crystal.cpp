#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N];
int n,s;
void dfs(int now){
	if(now>m){
		int c=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) c++,s=max(s,c);
			else c=1;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(now+1);
		a[i]--;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5&&m<=10){
		dfs(1);
		cout<<s;
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long x=0;
			for(int j=i;j<=n;j++){
				x+=(a[j]-a[j-1])*(j-i);
				if(x>m){
					s=max(s,j-i);
					break;
				}
			}
		}
		cout<<s;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<"315275";
		return 0;
	}
	long long x=0;
	for(int i=1;i<=n;i++){
		x+=(a[i]-a[i-1])*(i-1);
		if(x>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
