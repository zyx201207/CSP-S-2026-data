//t 2026-10-31 9:07
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5;
int n,m,a[2*N],ans=-1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);//31 15 7 3 1
	for(int i=1;i<=n-m;i++){
		int num=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			num=num&a[j];
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
/* 15 1111 1+2+4+8
 * 12 1100 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/
