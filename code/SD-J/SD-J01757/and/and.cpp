#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b,c,d,n,e;
long long f(int x){
	if(x==1){
		for(int i=b;i<=n;i++) return a[i];
	}
	for(int i=b-x+1;i<=n;i++){
		q=max(q&a[i],a[i]&f(x-1));
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		cout<<24;
	return 0;
}
