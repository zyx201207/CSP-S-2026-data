#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[5*100001],maxn;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long cha=0,l=1,k=m;
		for(int j=i-1;j>=1;j--){
			cha=cha+a[i]-a[j];
			if(cha<=k){
				l++;				
			}
			else{
				break;
			}			
		}
		maxn=max(maxn,l);
	}
	cout<<maxn<<endl;
	return 0;
}	
