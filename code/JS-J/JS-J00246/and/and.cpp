#include <bits/stdc++.h>
using namespace std;
long long n,m,a[220000],max1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int c=a[i]^a[j];
			cout<<c<<endl;
			if(max1<c&&i!=j){
				max1=c;
			    }
		    }
	    }
	cout<<max1;
	return 0;
}
