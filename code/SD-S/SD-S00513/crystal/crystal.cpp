#include<iostream>
#include<algorithm>
using namespace std;
long long int n,a[500004],num,q,ans;
long long int m,i,j,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	for(i=1;i<n;i++){
		for(j=i+ans;j<=n;j++){
			num=0;
			q=1;
			for(k=i;k<j;k++){
				num=num+a[j]-a[k];
				if(num>m)break;
				q++;
			}
			ans=max(ans,q);
		}
	}
	cout<<ans;
	return 0;
}
