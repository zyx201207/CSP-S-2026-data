#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long s=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		x[i]+=x[i-1];
		cin>>a[i];
	}
	int j=1;
	for(int i=n;;){
		
		long long ni=x[i]-x[i-1];
		long long nj=x[j]-x[j-1];
		if(ni==0){
			i--;ni=x[i]-x[i-1];
		} 
		if(nj==0){
			j++;nj=x[j]-x[j-1];
		} 
		
		long long minn=min(ni,nj);
		if(a[i]!=a[j]){
			s+=minn;
		}
		x[i]=x[i]-minn;
		x[j-1]=x[j-1]+minn;
		if(i==j) break;
	}
	cout<<s;
	return 0;
} 
/*
6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
 */
