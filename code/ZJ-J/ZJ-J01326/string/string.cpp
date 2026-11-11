#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	char zi;
	long long sum;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].zi;
	}
	for(int i=1,j=n;i<j;i++){
		while(a[i].sum && i<j){
			if(a[i].zi==a[j].zi){
				if(a[i].sum<=a[j].sum){
					a[j].sum-=a[i].sum;
					a[i].sum=0;
				}
				else{
					a[i].sum-=a[j].sum;
					a[j].sum=0;
				}
			}
			else{
				if(a[i].sum<=a[j].sum){
					a[j].sum-=a[i].sum;
					ans+=a[i].sum;
					a[i].sum=0;
				}
				else{
					a[i].sum-=a[j].sum;
					ans+=a[j].sum;
					a[j].sum=0;
				}
			}
			if(a[j].sum==0)j--;
		}
	}
	cout<<ans;
	return 0;
}
