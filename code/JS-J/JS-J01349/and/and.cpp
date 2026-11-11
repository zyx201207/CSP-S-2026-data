#include<bits/stdc++.h>
using namespace std;
long long a[200001],used[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,s=0,v=INT_MIN,b=INT_MIN,w;
	cin>>m>>n;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		s=a[i];
		for(long long j=1;j<=m;j++){
			used[j]=0;
		}
		for(long long j=1;j<n;j++){
			for(long long k=1;k<=m;k++){
				if(i!=k){
					if((s&a[k])>v&&used[k]==0){
						v=(s & a[k]);
						w=k;
					}
				}
			}
			s=v;
			v=INT_MIN;
			used[w]=1;
		}
		b=max(b,s);
	}
	cout<<b;
	return 0;
}
