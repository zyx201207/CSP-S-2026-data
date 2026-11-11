#include<bits/stdc++.h>
using namespace std;
int a[500005],s[100005],f[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,i,j,k,l,t;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(l=1;l<=m;l++){
			f[l]=0;
		}
		for(j=i;j<=n;j++){
			for(k=1;k<=j;k++){
				if(a[k]==a[j]){
					for(l=k+1;l<=j;l++){
						a[l]=0;
					}
					break;
				}
			}
		}
		for(j=1;j<=m;j++){
			t=a[j];
			if(f[t]==0){
				s[t]++;
				f[t]=1;
			}
		}
	}
	for(i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
    return 0;
}
