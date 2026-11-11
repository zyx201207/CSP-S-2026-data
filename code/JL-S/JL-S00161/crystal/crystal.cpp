#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[n-1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0) b[i-1]=a[i]-a[i-1];
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(a[x]<a[y]){
				int t=a[x];
				a[x]=a[y];
				a[y]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		//cout<<a[i]<<" ";
		if(i!=0){
			b[i-1]=a[i]-a[i-1];
			//cout<<b[i-1];
		}
		//cout<<endl
	}
	int t=0;
	for(int i=0;i<(n-1)/2;i++){
		if(b[i]<b[n-2-i]){
			t=0;
			break;
		}
		else if(b[i]>b[n-2-i]){
			t=1;
			break;
		}
	}
	int sum=1;
	if(t==0){
		for(int i=0;i<n-1;i++){
			if(m>=(b[i]*(i+1))){
				m-=(b[i]*(i+1));
				sum++;
			}
			else{
				break;
			}
		}
	}
	else if(t==1){
		for(int i=0;i<n-1;i++){
			if(m>=(b[n-2-i]*(i+1))){
				m-=(b[n-2-i]*(i+1));
				sum++;
			}
			else{
				break;
			}
		}
	}
	cout<<sum;
	freopen("crystal.in.txt","r",stdin);
	freopen("crystal.out.txt","w",stdout);
}
