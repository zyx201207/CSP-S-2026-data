#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e3+3;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",strout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int l=1,r=n-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]==a[i]){
				for(int j=mid;j<=i-1;j++){
					a[j]=0;
				}break;
			}
		}
	}for(int i=1;i<=n;i++){
		if(a[i])cout<<a[i]<<endl;
	}
	return 0;
}
