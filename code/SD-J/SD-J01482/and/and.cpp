#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
 	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int t=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]%2==0){
    		t=1;
		}
	}
	sort(a+1,a+1+n);
	//cout<<a[1];
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long m;
		m=a[1]&a[2];
		for(int i=3;i<=n;i++){
			m=m&a[i];
		}
		cout<<m;
		return 0;
	}
	if(t==0){
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
} 
