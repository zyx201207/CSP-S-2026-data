#include<bits/stdc++.h>
using namespace std;
long long a[10001000],b[1000000],m,n;
int main(){
	freopen("card4.in","r",stdin);
	//freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	   cin>>a[i];
	   b[a[i]]++;
    }
    for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;i++){
	        cout<<b[i*j]<<" ";
        }
    }
	return 0;
}