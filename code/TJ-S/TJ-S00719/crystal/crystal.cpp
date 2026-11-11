#include<iostream>
using namespace std;
const int N=1e6;
int a[N];
int main (){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n=0,m=0,t=0,c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t=max(t,a[i]);
	}
	int tmp=m+10,ans=0;
	while(tmp>m){
		tmp=0;
		ans=0;
		for(int i=0;i<n;i++){
			if(a[i]<=t){
				tmp+=t-a[i];
				ans++;
			}
		}
		t--;
	}
	c=ans;
	cout<<c;
	return 0;
}
