#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int num=1,cnt=1;
	for(int i=2,j=1;i<=n;i++){
		if((i-j)*(a[i]-num)<=m){
			cnt++;
			m-=(i-1)*(a[i]-num);
			num=a[i];
		}
		else m+=num-a[j],j++;
	}
	cout<<cnt;
	return 0;
}  
