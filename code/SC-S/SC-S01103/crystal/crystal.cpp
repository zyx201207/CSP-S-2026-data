#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum2,sum;
long long num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n<=5000&&m<=1000000){
		for(int i=1;i<=n;i++){
			sum2=1;
			int j=i;
			while(m>=(a[j]-a[j-1])&&j>0){
				m-=(a[j]-a[j-1]);
				a[j-1]=a[j];
				j--;
				sum2++;
			}
			if(sum2>sum)sum=sum2;
		}
		cout<<sum;
	}else{
	    sum=1;
		num=(a[1]+a[n])>>1;
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[mid]<num){
				l++;
			}else if(a[mid]>num){
				r--;
			}else{
				break;
			}
		}
		while(m>=(a[mid]-a[mid-1])&&mid>0){
			m-=(a[mid]-a[mid-1]);
			a[mid-1]=a[mid];
			mid--;
			sum++;
		}
	    cout<<sum;
	}
	return 0;
}