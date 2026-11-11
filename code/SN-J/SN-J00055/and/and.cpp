#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100000],t;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
	}
	if(m==2){
	    cout<<a[0] and a[1];
    }
    if(m==3){
	    cout<<a[0] and a[1] and a[2];
    }
    return 0;
}
