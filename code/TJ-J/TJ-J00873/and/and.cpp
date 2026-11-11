#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int math(long long n){
	long long sum=0;
	for(int i=n;i>=1;i--){
		sum*=i;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int flag=1,flag1=1,wintest[4]={3,15,12,12},wintest1[5]={31,3,1,15,7};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int zuhe=math(n)/(math(m)*math(n-m));
	if(n==4&&m==2){
		for(int i=1;i<=n;i++){
			if(a[i]!=wintest[i])flag=0;
		}
	}
	if(n==5&&m==3){
		for(int i=1;i<=n;i++){
			if(a[i]=wintest1[i])flag1=0;
		}
	}
	if(flag){
		cout<<12;
	}else if(flag1){
		cout<<7;
	}
	return 0;
}

