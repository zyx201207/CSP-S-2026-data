#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn],b[maxn],maxx=INT_MIN,l=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]>=l){
			l=a[i];
		}
	}
	if(m==0){
		for(int i=1;i<=l;i++){
			if(b[i]>maxx){
				maxx=i;
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<n/2+1;
	return 0;
} 
