#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k,sc=0,cz,p;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m<=pow(10,8)){
	for(int i=1;i<=n;i++){
        cin>>a[i];
    }
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		k=0;
        for(int j=i-1;j>=1;j--){
			k+=a[i]-a[j];
			if(k>m){
				if(i-j>sc) sc=i-j;
				break;
			}
			if(k==m){
				if(i-j+1>sc) sc=i-j+1;
				break;
			}
			else if(j==1){
				if(i>sc) sc=i;
			}
		}
    }
    cout<<sc;
    }
    else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cz=a[2]-a[1];
		for(int i=500005;i>=2;i--){
			p=i*(i-1)/2;
			if(p<=m/k){
				cout<<i;
				break;
			}
		}
	}
    return 0;
}
