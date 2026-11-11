#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	int maxn=-1;
	for(int i=0;i<n;i++){
		int ans=0,m1=m;
		for(int j=i;j<n;j++){
			if(m1>=abs(a[i]-a[j])){
				m1-=abs(a[i]-a[j]);
				ans++;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
