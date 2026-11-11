#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
//int sum[300005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
//		sum[a[i]]++;
	} 
	for(int i=0;i<m;i++){
		cout<<n<<" ";
	}
	return 0;
}
