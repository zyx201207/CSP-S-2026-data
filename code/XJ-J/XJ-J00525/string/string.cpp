#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0, n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	long long ans=0;
	sum/=2;
	long long j=1,i=1;
	while(i<n-j+1){//
		if(a[i].num>a[n-j+1].num){
			if(a[i].c!=a[n-j+1].c){
				
				ans+=a[n-j+1].num;
				
			}
			a[i].num-=a[n-j+1].num;
			j++;
		}else if(a[i].num<a[n-j+1].num){
			if(a[i].c!=a[n-j+1].c){
				
				ans+=a[i].num;
				
			}
			a[n-j+1].num-=a[i].num;
			i++;
		}else{
			if(a[i].c!=a[n-j+1].c){
				ans+=a[i].num;
			}
			i++,j++;
		}
	}
	cout<<ans;
	return 0;
}