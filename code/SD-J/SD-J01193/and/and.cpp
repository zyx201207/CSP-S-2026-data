#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
long long jz(long long a){
	long long i=0;long long b[10000];
	while(a!=0){
		i+=1;
		b[i]=a%2;
	}
	for(int j=0;j<i;j++){
		return b[j];	
	}
}
long long yuyu(long long a[1000000],long long b[1000000],long long c[1000000]){
	for(int i=0;i<100000;i++){
		if(a[i]==b[i]==1) c[i]=1;
		else c[i]=0;
	}
	for(int j=0;j<100000;j++){
		return c[j];
	}

}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[N],sz[m],res[N];
	for(int i=0;i<m;i++){
		cin>>sz[m];
	}
	long long max1=0,max2=0;
	for(int i=0;i<m;i++){
		if(a[i]>=max1) max1=a[i];
		else if(a[i]>max2) max2=a[i];
	}
	yuyu(jz(max1),jz(max2),res[N]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

