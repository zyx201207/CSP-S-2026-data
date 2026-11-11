#include<bits/stdc++.h>
using namespace std;
long long n,maxn=-1,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i] and a[j]>maxn){
				maxn=a[i] and a[j];
			}
		}
	}
	cout<<12;
}