#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	int n,m,a[500001],b[500001],c=0;
	cin>>n>>m;
	bool g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum,summ=0,l=m;
	sum=m-a[1];
	for(int i=n;i>0;i--){
		if(a[i]==sum){
			summ++;
		}else if(a[i]<sum){
			if(m<sum-a[i]){
				break;
			}else{
				m-=sum-a[i];
				summ++;				
			} 
			
		}
	}
	cout<<summ;
	return 0;
}
