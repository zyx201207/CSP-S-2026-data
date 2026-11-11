#include<bits/stdc++.h>
using namespace std;
string s="",p="";
char c[100005];
int a[100005],n,m,maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(maxx==a[i]){
			cnt++;
		}
	}
	if(cnt>=m){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			maxx=(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}
