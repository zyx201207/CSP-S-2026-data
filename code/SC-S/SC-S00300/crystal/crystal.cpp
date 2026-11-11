#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],q[1000005],num=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			long long t=0;
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
		else continue;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long c=b[i]+m;
		long long sum=c/i;
		if(sum*i==c){
			if(sum>=a[i]){
				num=i;
			}
			else break;
		}
		else continue;
		
	} 
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}