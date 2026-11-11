#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int c[500010];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(n==1){
	  cout<<1;
	  return 0;	
	}
	else if(m==1){
		cout<<n;
		return 0;
	}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k>=1;k--){
                if(a[j]==a[k]){
                    for(int l=k;l<=j;l++){
                        a[l]=0;
                    }
                } c[b[i]]+=a[j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
