#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	int c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c=c+a[i];
	}
	int p=c/n,r,t;
		if(a[1]-p>=0){
			r=a[1]-p;
		}else if(p-a[1]>=0){
			r=p-a[1];
		}
	for(int i=0;i<n;i++){
		int b;
		if(a[i]-p>=0){
			b=a[i]-p;
		}else if(p-a[i]>=0){
			b=p-a[i];
		}
		if(b<r){
			r=b;
			t=i;
		}
	}
	int l=t-1,z=t+1,q=1;
	for(int i=0;i<n;i++){
		int v,j;
		if(a[t]-a[l]>=0){
			v=a[t]-a[l];
		}else{
			v=a[l]-a[t];
		}
		if(a[t]-a[z]>=0){
			j=a[t]-a[z];
		}else{
			j=a[z]-a[t];
		}
		if(v<=j and m-v>=0){
			m=m-v;
			q+=1; 
			l--;
		}else if(j<=v and m-j>=0){
			m=m-j;
			q+=1;
			z++;
		}
		if(m-v<0 and m-j<0){
			break;
		}
	}
	cout<<q;
	return 0;
}
