#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	int m2=0;
	int ans[n];
	int num=0;
	int sum=0;
	for(int i=0;i<n;i++){
		if(m2>m){
			ans[sum]=num-1;
			sum++;
			num=0;
			i=sum;
		}
		if(m2==m){
			ans[sum]=num;
			sum++;
			num=0;
			i=sum;
		}
		m2=m2+a[i+1]-a[i];
		num++;	
	}
	int cnt=max(ans[0],ans[n]);
	cout<<cnt+1;
	return 0;
}
