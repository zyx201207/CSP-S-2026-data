#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		while(c){
			a[i]+=c%2;
			c/=2;
		}
	}
	sort(a,a+n);
	int maxa=0,maxb=0;
	for(int i=0;i<n;i++){
		maxb=a[i] and a[i+1];
		maxa=max(maxa,maxb);
	}
	cout<<maxa+n;
	return 0;
}
