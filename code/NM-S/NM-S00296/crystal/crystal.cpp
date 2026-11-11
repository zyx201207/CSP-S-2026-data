#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,ans;
long long m,a[N],c[N],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			if(c[j]>m||sum+(j-i+1)*c[j]>m){
				ans=max(ans,j-i+1);
				break;
			}
			else{
				sum+=(j-i+1)*c[j];
			}
		}
	}
	cout<<ans;
	return 0;
} 
