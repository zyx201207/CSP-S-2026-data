#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxi,maxn;
void and1(){
	for(int i=0;i>=n;i++){
		for(int j=i+1;j<n-1;j++){
			long long int x=a[i]&a[j];
			maxn=max(x,maxn);
		}
	}
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	and1();
	if(m==1){
		cout<<maxi;
	}else cout<<maxn;
	return 0;
} 
