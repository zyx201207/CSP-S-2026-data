#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		int sum,l,c[N];
		sum=0,l=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				c[++l]=i-a[j];
			}
		}
		sort(c+1,c+1+l);
		int len=0;
		for(int j=1;j<=l;j++){
			if(sum<=m){
				sum+=c[j];
				len++;
			}
			else{
				break;
			}
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}