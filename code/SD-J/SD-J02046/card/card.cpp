#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int ans=1;
		for(int i=1;i<=n;i++){
			for(int k=1;k<i;k++){
					a[k]=0;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
//					cout<<i<<" "<<j<<"!"<<endl;
					for(int k=i;k<j;k++){
						a[k]=0;
					}
				}
			}
//			for(int z=i;z<=n;z++){
//				cout<<a[z]<<" ";
//			}
//			cout<<endl;
			for(int k=i;k<=n;k++){
//				cout<<a[k]<<" ";
				b[a[k]]+=1;
//				cout<<b[a[k]]<<"*"<<endl;
			}
//			cout<<endl;
			for(int j=1;j<=n;j++){
				a[j]=c[j];
			} 
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
return 0;
}
