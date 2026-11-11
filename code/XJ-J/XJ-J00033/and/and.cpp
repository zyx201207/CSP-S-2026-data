#include<bits/stdc++.h> 
using namespace std;
const long long N=1e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int max=0;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=0;i<n;i++){
//		for(int j=i;j<n;j++){
//			if(a[j]&a[j+1]>max){
//				max=a[j]&a[j+1];
//			}
//		}
//	}
	sort(a,a+n+1);
	int c=a[n];
	for(int i=n;i>=m;i--){
		c=c&a[i];
//		cout<<c<<" ";
//		cout<<a[i]<<" ";
	}
	cout<<c;
//	78&43&23 1
	return 0;
}
