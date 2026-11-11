#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long n,m,a[N],d[N],mn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	long long c=0;
	bool tx=true;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(i==2) c=a[2]-a[1];
		else{
			if(a[i]-a[i-1]!=c){
				tx=false;
			}
		}
	}
	if(tx){
		mn=1;
		long long sum=0,ns=0;
		for(long long i=2;i<=n;i++){
			ns+=c;
			sum+=ns;
			if(sum<=m){
				mn++;
			}
			else{
				break; 
			} 
		}
		cout<<mn;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++){
		long long sum=0,ns=0,j=i;
		for(j=i-1;j>0;j--){
			ns+=d[j+1];
			sum+=ns;
			if(sum<=m){
				mn=max(mn,i-j+1);
			}
			else{
				j++;
				break; 
			} 
		}
	}
	cout<<mn;
	return 0;
}