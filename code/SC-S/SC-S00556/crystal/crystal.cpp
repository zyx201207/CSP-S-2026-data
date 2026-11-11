#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int a[n]={ };
	long long al[n]={};
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=-1,record=0,p=1;
	for(int i=1;i<n;i++){
		al[i]=al[i-1]+a[i];
	}
	for(int i=p;i<n;i++){
		for(int j=record;j<i;j++){
			if((long long)1*(i-j)*a[i]-(al[i-1]-al[j]+a[j])<=m){
				if(i-j+1>ans) ans=i-j+1;
				record=j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}