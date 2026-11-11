#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,b[200005];
int search(int y){
	for(int i=1;i<=n;i++){
		if(b[i]!=-1)continue;
		b[y]=a[i];
		return search(y-1);
		b[y]=0;
	}int ans=b[m];if(y==0){
		for(int i=m;i>=m;i--)ans=ans&b[i];
		return ans;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int max=0;
	for(int i=1;i<=n;i++){
		b[1]=a[i];
		int j=search(m);
		if(max<j)max=j;
		b[m+1]=-1;
	}
	cout<<max;
	return 0;
}
