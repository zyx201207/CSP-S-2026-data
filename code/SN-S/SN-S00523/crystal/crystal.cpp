//程楚焱 SN-S00523 延安市新区培文学校 
#include<bits/stdc++.h>
using namespace std;

const int N=5e5;
int a[N];
int n;
long long m;
int num(int x){
	long long num1=m;
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==x){
			ans++;
			continue;
		}
		if(a[i]<x&&num1>=0&&num1-(x-a[i])>=0){
			num1=num1-(x-a[i]);
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long o=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		o+=a[i];
	}
	o/=n; 
	for(int i=0;i<n;i++){
		if(a[i]==o){
			cout<<num(o);
			return 0;
		}
	}
	cout<<num(o+1);
}
