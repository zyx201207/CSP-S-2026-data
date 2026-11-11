#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
const int Max=1e6+10;
long long a[Max],g[Max];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	int q=n/2;
	int b=q;
	q=a[q];
	int c=m;
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		
		if(q>=a[i]){
			cnt++;
			g[i]=q-a[i];
			sum+=g[i];
		}
		
		
	}
	cout<<cnt;
	return 0;
} 