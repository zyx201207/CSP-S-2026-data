#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;


			for(int k=j;k<=n;k++){
				if(a[j]==a[k]){
					for(int q=j;q<k;q++){
						b[a[q]]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
