#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int max_a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n/2;i<=n;i++){
		int num=0,r=m;
		for(int j=i;j>=1;j--){
			if(r-(a[i]-a[j])>=0){
				r=r-(a[i]-a[j]);
				num++;
			}
			else{
				break;
			}
		}
		max_a=max(max_a,num);
	}
	cout<<max_a;
	return 0;
}
