#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long c=0;
	int t=0;
	for(int i=0;i<n-1;i++){
		for(int j=i;j<m;j++){
			long long b=a[j]&a[j+1];
			if(b>c){
				c=b;
			}
		}
	}
	cout<<c;
	return 0;
}
