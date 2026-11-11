#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],b[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;	
		}
	sort(a+1,a+1+n);
	for(int i=n;i>0;i--){
		int k=m;
		for(int j=i-1;j>0;j--){
			if(k>=0){
				k-=a[i]-a[j];
				b[i]++;
			}
			if(k<0)b[i]--;
		}
	}
	sort(b+1,b+1+n);
	cout<<b[n];
	return 0;
}
