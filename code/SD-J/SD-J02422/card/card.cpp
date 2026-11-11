#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],sum[300005],l=0,r=0;
void fa(int x){
	int y=0;
	for(int s=1;s<=l;s++){
		if(b[s]==a[x]){
			y=s;
		}
		if(y!=0){
			b[s]=0;
			
		}
	}
	if(y!=0){
		l=y;
		b[y]=a[x];
		
	}
	if(y==0){
		b[l+1]=a[x];
		l++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			r=1;
		}
	}
	if(r=0){
		for(int i;i<=m;i++){
			cout<<"1 ";
		}
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			fa(j);	
		}
		for(int j=1;j<=l;j++){
//			cout<<b[j]<<" ";
			sum[b[j]]++;
			b[j]==0;
			
		}
		l=0;
//		cout<<endl;
	}
//		for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	
	
	
	
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
