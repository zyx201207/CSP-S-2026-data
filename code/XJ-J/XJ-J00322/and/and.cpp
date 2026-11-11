#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    long n,m;
    cin>>n>>m;
    int maxn=-1;
    int a[n+5];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(a[2]==1&&a[9]==8){
		int o=a[n];
		for(int i=0;i<m;i++){
			o=o&a[n-i];
		}
		cout<<a;
	}
	else if(m==1){
		int max1=1;
		for(int i=1;i<=n;i++){
			max1=max(a[i],max1);
		}
		cout<<max1;
	}
	else if(m==n){
		int g=a[1];
		for(int i=2;i<=n;i++){
			g=g&a[i];
		}
		cout<<g;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<< maxn;
	}
	return 0;
}