#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,mt,max=0;
	cin>>n;
	cin>>m;
	long long a[n]={0};
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	if(n==1||m==0){
		cout<<1;
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<=n-1;i++){
		int lt=0;
		long long l=i-1,cnt=1;
		mt=m;
		while(1){
			if(a[i]-a[l]<=mt){
				cnt=cnt+1;
				mt=mt-(a[i]-a[l]);
				if(l-1>=0){
					l=l-1;
				}else{
					break;
				}
			}else{
				break;
			}
		}
		if(cnt>max){
			max=cnt;
		}
	}
	cout<<max;
	return 0;
}
