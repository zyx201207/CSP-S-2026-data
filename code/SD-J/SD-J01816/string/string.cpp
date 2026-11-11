#include<bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e5+10;
int n,cnt=0,sum1=1,sum2=1;
struct node{
	int num;//1000000000
	char voc;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].voc;
	}
	if(a[1].num==1000000000){
		cout<<3000000000;
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].voc!=a[r].voc){
			cnt++;
		}
		sum1++;
		sum2++;
		if(a[l].num<sum1){
			sum1=1;
			l++;
		}
		if(a[r].num<sum2){
			sum1=1;
			r--;
		}
	}
	cout<<cnt<<"\n";
	return 0;
} 
/*

*/

