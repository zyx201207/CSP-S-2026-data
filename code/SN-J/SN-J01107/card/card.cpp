#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[500005],ans[500005];
int f(int x){
	for(int i=1;i<=n;i++){
		if(b[i]==x){
			return i;
		}
	}
	return 0; 
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=f(j);
			if(s){
				for(int k=s;k<j;j++){
					b[k]=0;
				}
				b[s]=a[j];
				cout<<b[j]<<" ";
			}else{
				b[j]=a[j];
			}
			cout<<b[j]<<" ";
		}
		cout<<"\n";
//		for(int j=1;j<=n;j++){
//			ans[b[j]]++;
//		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<ans[i]<<" ";
//	}
}
