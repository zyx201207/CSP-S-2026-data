#include<bits/stdc++.h>
using namespace std;
long long a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long mx=-1,now=a[1],nowl=1;
	for(int i=0,j=1;j<=n;){
		i++;
		if(i>j) break;
		now-=a[j]-a[i-1];
		while(now<=m){
			if(j<n){
				j++;
				now+=nowl*d[j];
				nowl++;
			}
			else break;
		}
		if(j>n) break;
		nowl--;
		mx=max(mx,nowl);
	}
	cout<<mx<<endl;
	return 0; 
}
