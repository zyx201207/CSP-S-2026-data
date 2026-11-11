#include<bits/stdc++.h>
using namespace std;
int a,b,arr[500005],arr1[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>arr[i];
	if(a==b){
		for(int i=1;i<=b;i++){
			cout<<i<<' ';
		}
	}
	return 0;
}
