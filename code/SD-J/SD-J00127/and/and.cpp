#include<bits/stdc++.h>
using namespace std;
const int SIZE = 2*1e5+2;
int n,m,a[SIZE];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int maxn=INT_MIN;
	if(m==1){
		cout<<a[n]<<'\n';
		return 0;
	}
	else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int m=a[i] and a[j];
				maxn=max(m,maxn);
			}
		}
	} 
	cout<<maxn<<'\n';
	return 0;
}
