#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				mx=max(a[i],a[j]);
			}
		}
		cout<<mx;
	}
	else if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			mx=max(mx,x);
		}
		cout<<mx;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
