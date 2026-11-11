#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum1=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		sum1&=a[i];
	}
	int cnt=1;
	int ans=a[n];
	if(m<=3 and n<=2003){
		while(cnt<m){
			int max=0,flag=0;
			for(int i=1;i<=n-1;i++){
				if(ans&a[i]>max){
					max=ans&a[i];
					flag=i;
				}
			}
			ans=max;
			a[flag]=0;
			cnt++;
		}
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		sum&=a[i];
	}
	if(sum==0 and sum1!=0) sum=sum1;
	cout<<max(sum,ans);
	return 0;
}
