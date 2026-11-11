#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200001];
	int ch1[200001];
	char ch2;
	long long cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch2;
		ch1[i]=ch2-0;;
	}
	double x=n/2.0;
	int y=ceil(x);
	int i=0,j=n+1;
	long long p=0;
	int i1,j1;
	while(1){
		if(ch1[++i]!=ch1[--j]){
			cnt+=min(a[i],a[j]);
			i1=a[i];
			j1=a[j];
			a[i]-=min(i1,j1);
			a[j]-=min(i1,j1);
			if(a[i]==0){
				i++;
				if(a[i]!=a[j])cnt+=min(a[i],a[j]);	
			}
			if(a[j]==0){
				j--;
				if(a[i]!=a[j])cnt+=min(a[i],a[j]);
			}
		}
		if(i>=y||j<=y){
			break;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
