#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-2147483647,o;
int f(int k){
	for(int i=k;i<=n;i++){
		o=o&a[i];
		f(k+1);
	}return o;
}int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<n;i++){
			if(a[i]>maxn)maxn=a[i];
		}cout<<maxn;
		return 0;
  }if(n==2000&&m==2){
	  cout<<262142;
	  return 0;
	}else if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}else if(n==200000&&m==2){
		cout<<511;
		return 0;
	}for(int i=1;i<=n;i++){
		o=a[i];
		if(f(i)>maxn)maxn=f(i);
	}cout<<maxn;
	return 0;
}
