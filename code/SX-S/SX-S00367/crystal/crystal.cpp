#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int a[N];
long long int cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int m,n,f=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>=2){
			if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
				f=1;
			}
		}if(i>=1){
			cha[i]=a[i]-a[i-1];
		}
	}sort(a,a+n);
//特判首
	if(f==0){
		long long int ssr=m/(a[1]-a[0]),cnt=1;
		for(int i=(a[1]-a[0]);;i+=(a[1]-a[0])){
			ssr-=i;
			if(ssr<0){
				cout<<cnt<<endl;
				return 0;
			}else if(ssr==0){
				cout<<cnt+1<<endl;
				return 0;
			}else{
				cnt++;
			}
		}
	}
//特判尾
long long int maxx=-1234567890,sum=0;
	for(long long int i=2;i<=n;i++){
		sum=0;
		for(long long int j=i-1;j>=1;j--){
			for(long long int k=1;k<=i-j;k++){
				sum+=((a[i]-a[j+k])*k);
			}if(sum>m){
				maxx=max(maxx,i-j-1);
				continue;
			}else if(sum==m){
				maxx=max(maxx,i-j);
				continue;
			}else{
				maxx=max(maxx,i-j);
			}
		}
	}cout<<maxx;
	return 0;
}