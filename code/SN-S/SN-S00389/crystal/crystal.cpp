#include<bits/stdc++.h>
using namespace std;
int a[500001]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	sort(a+1,a+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i]+1){
			sum++;
		}
		else{
			if(a[i]+1-a[i]<=m){
				sum++;
				int cha=a[i+1]-a[i];
				m-=cha;
			}
		}
	}
	cout<<sum;
	return 0;
}
