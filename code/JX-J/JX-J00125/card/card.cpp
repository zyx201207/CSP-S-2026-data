#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],b[100001],x[100001];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=a[j];
            for(int k=1;k<=j;k++){
                if(b[k]==b[j]){
                    for(int l=1;l<=k;l++){
                       b[l]=0;
                    }
                }
            }
        }
        for(int j=1;i<=n;j++){
            if(b[j]!=0) x[b[j]]++;
        }
	}
	for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
	}
	return 0;
}
