#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],n,m;
int cmp(int a,int b){
	return a<b; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;//几个，至多
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int sum=0;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<i;j++){
			
			if(sum>m){
				cout<< j+1;
				return 0;
				
			} 
			sum=sum+(a[i]-a[j]);
		}
	}
	cout<<1;
	return 0;
}//int s=a[i],j=1,sum=0;
//		while(i--){
//			if(sum>m){
//				cout<<j;
//				return 0;
//			}	
//			sum=sum+(s-a[j]);
//			j++;
//		}
