#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m,y=0,r=0;
int w[N]={0},max1=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>w[i];
		max1=max(max1,w[i]);
	}
	y=w[0]|w[1];
	if(m==1){
		cout<<max1;
	}else if(m==n){
		for(int i=2;i<n;i++){
			y=y&w[i];
		}
		cout<<y;
	}else if(m==2){
		max1=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				max1=max(max1,(w[i]&w[j]));
			}
		}
		cout<<max1;
	}else{
		r=(w[n-m]&w[n-m+1]);
		for(int i=n-m+2;i<n;i++){
			r=r&w[i];
		}
		cout<<r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
