#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		scanf("%d",a[i]);
		if(i==1) continue;
		if(a[i]-a[i-1]>0) b[i-1]=a[i]-a[i-1];
		else if(a[i]-a[i-1]<0) b[i]=a[i-1]-a[i];
	}
	sort(b+1,b+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	int x=0;
	for(int i=1;i<=n;i++){
		if(m-b[i]>=0){
			m-=b[i];
			x++;
		}
	}
	cout<<x;
	return 0;
} 
