//80-100
#include<bits/stdc++.h>
using namespace std;
long long int a[500010],d1[500010],d2[500010],sum1[500010],sum2[500010],c[500010];
int N;	
long long int M;
bool check(int x){
	long long int cs=0;
	for(int i=1;i+x<=N;i++){
		//long long int num1=max(sum2[i]-(i-1)*sum1[i]+cs,0*1ll);
		long long int num2=sum2[i+x-1]-(i-1)*sum1[i+x-1]+cs;
		//cout<<i<<" "<<x<<" "<<" "<<num2<<endl;
		if(num2<=M){
			return 1;
		}
		cs+=sum1[i];
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	

	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+N+1);
	for(int i=2;i<=N;i++){
		d1[i]=a[i]-a[i-1];
		d2[i]=(i-1)*d1[i];
		sum1[i]=sum1[i-1]+d1[i];
		sum2[i]=sum2[i-1]+d2[i];
		//cout<<sum1[i]<<" "<<sum2[i]<<" "<<endl;
	}
	int l=1,r=N,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==1){
			ans=mid;
			l=mid+1;
			
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

/*
 n___n
/'  ' \
\o ^ o/
/     \ 
--this is little white mouse,not hamster--
the last time,probably.
I have nothing to say,but wish you RP++.
*/
