#include<bits/stdc++.h>
using namespace std;
int a[200003];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxxi=0,maxi2=0,ss=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ss&=a[i];
		if(a[maxxi]<a[i])maxxi=i;
	}
	for(int i=0;i<n;i++){
		if(i==maxxi)continue;
		if(a[maxi2]<a[i])maxi2=i;
	}
	if(m==1){
		cout<<a[maxxi];
		return 0;
	}
	if(m==n){
		cout<<ss;
		return 0;
	}
	cout<<(a[maxxi]&a[maxi2]);
	return 0;
}
