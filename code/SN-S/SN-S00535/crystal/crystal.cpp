//SN-S00535 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long a[500005]={};
long long sum[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long goh=a[2]-a[1];
	long long isg=0;
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]==goh){
			isg++;
		}
	}
	if(isg==n-1){
		long long count=0;
		for(long long i=1;;i++){
			m-=i*goh;
			count++;
			if(m<0){
				cout<<count;
				return 0;
			}
		}
	}
	long long corn=1;
	long long maxx=1;
	long long Lets_do_this=0;
	for(long long i=n;i>1;i--){
		for(long long j=i-1;j>=1;j--){
			Lets_do_this+=a[i]-a[j];
			if(Lets_do_this<=m){
				corn++;
				if(corn>maxx){
					maxx=corn;
				}
			}else{
				continue;
			}
		}
		Lets_do_this=0;
		corn=1;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
