#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,d,a[N];
signed main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				cout<<i<<"->"<<j<<endl;
			}
		}
	}
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

10 2
1 3 5 7 8 9 10 12 14 16
*/
