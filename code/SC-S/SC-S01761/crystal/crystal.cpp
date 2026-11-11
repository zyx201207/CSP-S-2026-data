#include<bits/stdc++.h>
using namespace std;
long long cha[500001];
int main(){
  	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int c=0;
	for(int i=0;i<n-1;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=0;i<n-1;i++){
		if(cha[i]==cha[i+1]){
			c++;
		}
	}
	if(c==n-2){
		cout<<m/cha[0]<<endl;
		return 0; 
	}
	int sum=0,x=0,ant=1;
	for(int i=1;i<n;i++){
		x+=ant*cha[i-1];
		ant++;
		if(x>m){
			int j=0;
			while(x>m){
				ant--;
				x-=a[i]+a[j];
				j++;
			}
		}
		sum=max(sum,ant);
	}
	cout<<sum<<endl;
	return 0; 
}