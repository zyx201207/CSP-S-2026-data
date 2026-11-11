#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[n+10],b[n+20];
	int f=1;
	int c=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) f=0;
		if(sqrt(a[i]+1)!=int(sqrt(a[i]+1))) c=0;
		b[i]=int(sqrt(a[i]))+1;
	}
	if(sqrt(n)==int(sqrt(n))&&f){
		for(int i=1;i<=b[n]-1;i++){
			cout<<1;
		}
		cout<<0;
		return 0;
	}
	if(c){
		for(int i=1;i<=b[n]-1;i++){
			cout<<1;
		}
		return 0;
	}
	return 0;
}
