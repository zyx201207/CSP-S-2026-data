#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	long long sum;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].s;
	}
	int i=1,j=n;
	long long cnt=0;
	while(i<j){
		if(a[i].s!=a[j].s){
			if(a[i].sum==a[j].sum){
				cnt+=a[i].sum;
				i++;
				j--;
			}
			else{
				cnt+=min(a[i].sum,a[j].sum);
				long long t=min(a[i].sum,a[j].sum);
				a[i].sum=a[i].sum-t;
				a[j].sum=a[j].sum-t;
				if(a[i].sum==0){
					i++;
				}
				if(a[j].sum==0){
					j--;
				}	
			}
		}
		else{
			if(a[i].sum==a[j].sum){
				i++;
				j--;
			}
			else{
				long long t=min(a[i].sum,a[j].sum);
				a[i].sum=a[i].sum-t;
				a[j].sum=a[j].sum-t;
				if(a[i].sum==0){
					i++;
				}
				if(a[j].sum==0){
					j--;
				}	
			}
		}
	}
	cout<<cnt;
	return 0;
} 
