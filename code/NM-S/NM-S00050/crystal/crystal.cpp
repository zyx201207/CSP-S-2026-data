#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    //susu
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }

    bool isok=true;
    for(long long i=0;i<n-1;i++){
        if(a[i]+1!=a[i+1])
            isok=false;
    }
    if(isok){
    	long long plas[m+1]={0};
    	for(long long i=1;i<=n;i++){
    		for(long long j=1;j<=i;j++){
    			plas[i]=plas[i]+j;//plas[1]鏄?鐨勯樁鍔?
			}
		}

		for(long long i=1;i<=m;i++){
			if(m<plas[i]){
				cout<<i;
				break;
			}
		}
	}

	else{
		long long diff[n-1];
		sort(&a[0],&a[n]);
		for(long long i=0;i<n;i++){
			diff[i]=a[i+1]-a[i];
		}
		long long plus[n-1]={0};
		for(long long i=0;i<n-1;i++){
			for(long long j=0;j<=i;j++){
				plus[i]=plus[i]+diff[j];
			}

		}

		for(long long j=0;j<n-1;j++){
			if(m<=plus[j]){
			cout<<j+1;
			break;
			}
		}
	}
}
