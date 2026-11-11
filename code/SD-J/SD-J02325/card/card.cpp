#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5+10;
long long n,m;
long long a[N];
bool w=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			for(int k=1+i;k<=n;k++){
				if(a[j]==a[k]){
					w=0;
					break;
				}
			}
			if(w){
				a[i]=a[i+1];
			}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			                                  }
	}
	while(m--){
		cout<<0<<" ";
	}
	return 0;
}
 
