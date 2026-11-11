#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
int n,m;
long long a[2000005],k=0,mx=0,sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int k=n-1;k>=0;k--){
		mx=a[k];
		sum=1;
		for(int i=k-1;i>=0;i--){
			 if(sum==m)break;
			 if((mx&a[i])>=mx){
			 	mx&=a[i];
			 	sum+=1;
			 }
		}
		if(sum==m)break;
	}
	cout<<mx;
	return 0;
}
