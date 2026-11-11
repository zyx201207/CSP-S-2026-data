#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	if(n<=20&&n!=m){
		int x=a[n];
		int j=0;
		for(int i=n-1;i>=n;i--){
	    	x=x&a[i];
	    	j++;
	    	if(j==m){
	    		break;
			}
		}
		cout<<x;
	}if(m==n){
		int x=a[1];
	    for(int i=2;i<=n;i++){
	    	x=x&a[i];
		}
		cout<<x;
	}if(a[n]==4){
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==4){
				f++;
			}
		}
		if(f>=m){
			cout<<4;
		}else{
			cout<<3;
		}
	}
    return 0;
}

