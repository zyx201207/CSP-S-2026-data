#include<bits/stdc++.h>
using namespace std;
long long s,n,m,a[5000005],b,k,sum,l=1,mid,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	s=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	/*while(r<=n){
		
		if(a[r]-a[l]>sum){
			sum=a[r]-a[l];
			k=r-l;
		}
		r++;
		while(a[r]-a[l]>m)l++;
	}*/
	while(a[s]==a[s+1])s++;
	for(long long i=1;i<m,s<n;m-=k){
		b=a[s+1]-a[1];k=b*s;
		if(m>=k){a[1]+=b;}
		else{break;}
		while(a[1]==a[s+1])s++;
		
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
