#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005],n,m,maxn=-1,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n==m){
		sum=a[0]&a[1];
		for(int i=2;i<n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				sum=a[i]&a[j];
				if(sum>maxn){
					maxn=sum;
				}
			}
		}
		cout<<maxn;
	}else if(n<=20){
		int b=1<<n;
		for(int i=0;i<b;i++){
			int s=0;
			for(int j=0;j<n;j++){
				if((1<<j)&(i)){
					s++;
				}
			}
			if(s==m){
				bool k=0;
				for(int j=0;j<n;j++){
					if((1<<j)&(i)){
						if(k==0){
							sum=a[j];
						}else{
							sum=sum&a[j];
						}
						k=1;
					}
				}
				if(sum>maxn){
					maxn=sum;
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}