#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[100010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=0;
	if(m==n){
		for(int i=1;i<=n;i++){
			q^=a[i];
		}
		cout<<q;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			q=max(q,a[i]);
		}
		cout<<q;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		q^=a[i]; 
	}
	cout<<q;
	return 0;
} 
