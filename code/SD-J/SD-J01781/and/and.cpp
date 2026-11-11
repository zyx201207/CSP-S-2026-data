#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,an;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	maxx=a[1];
	an=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		an=(an&a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==n){
		cout<<an;
		return 0;
	}else if(m==2){
		an=0;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				an=max(an,(a[i]&a[j]));
			}
		}
		cout<<an;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1]; 
	return 0;
} 
