#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int n,m,s;
	cin>>n>>m;
	long long a[10000];
	long long q[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		while(i!=0){
			s=0;
			int w=a[i];
			s=w/2;
			q[i]=w%2;
			w=s;
		}
	}
	while(m!=0){
		int r=1;
		s=0;
		s=m/2;
		a[r]=m%2;
		m=s;
		r++;
	}
	cout<<a[m];
	return 0;
}
