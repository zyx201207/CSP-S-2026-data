#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int t=0;
	for(int i=0;i<m;i++){
		t+=a[i];
	}
	int flag=t&(t+1);
	if(flag==0){
		cout<<a[m];
	}
	else{
		cout<<a[m-1];
	}
}
