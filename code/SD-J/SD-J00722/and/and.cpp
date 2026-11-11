#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx&=a[i];
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		maxx=0;
		for(int i=1;i<=n;i++){
			int cnt=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					cnt&=a[j];
				}
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	maxx=(1<<30)-1;
	for(int i=n;i>n-m;i--){
		maxx&=a[i];
	}
	cout<<maxx;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
