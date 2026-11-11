#include<iostream>
#include<cstring>
using namespace std;
int a[500005];
int sum[300005];
int num[300005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int bb=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			bb=0;
		}
		sum[a[i]]+=i;
	}
	if(bb==1){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				sum[a[i]]--;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				num[a[j]]=j;
			}else{
				for(int k=num[a[j]]+1;k<j;k++){
					num[a[k]]=0;
					b[a[k]]=0;
					sum[a[k]]--;
				}
				sum[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
