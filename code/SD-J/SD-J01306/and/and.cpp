#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],mx=0,v=0;
bool b(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n-m+1;i++){
		for(long long j=i;j<n-m+1;j++){
			v=a[i];
			for(long long l=0;l<m-1;l++){
				v=(v&a[j+l+1]);
			}//次数 
			mx=max((long long)mx,(long long)v);	
		}//次高 
	} //最高 
	cout<<mx;
} 
