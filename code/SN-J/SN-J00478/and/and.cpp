#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m,a[100005],p;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				p=a[j];
				a[j]=a[i];
				a[i]=p;
			}
		}
	}
	cout<<a[m-1];
	return 0;
}

