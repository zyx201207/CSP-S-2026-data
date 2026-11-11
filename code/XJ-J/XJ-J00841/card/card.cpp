#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N]={-1};
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (int j=1;j<=i-1;j++){
			if (a[j]==a[i]){
				for (int k=j;k<i;k++){
					a[k]=0;
				}
				s++;
			}
		}
	}
    for (int i=1;i<=n;i++){
    	if (a[i!=-1])cout<<a[i];
	}
	
	return 0;
} 

