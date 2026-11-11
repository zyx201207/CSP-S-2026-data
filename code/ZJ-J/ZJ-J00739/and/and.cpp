#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],k[200100][30],b[30];
bool cmp(int x,int y){
	return x>y;
}
void Ten_to_Two(int s){
	int t[30]={},x=30,y=a[s];
	while(y>0){
		t[--x]=y%2;
		y/=2;
	}
	for(int i=0;i<=29;i++){
		k[s][i]=t[29-i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		Ten_to_Two(i);
	}
	for(int i=29;i>=0;i--){
		int p=0,tot=0;
		for(int j=1;j<=n;j++){
			if(k[j][i]==1){
				tot++;
			}
		}
		if(tot<m)continue;
		else{
			for(int j=1;j<=n;j++){
				if(k[j][i]==1){
					swap(k[j],k[++p]);
				}
			}
			n=tot;
			b[i]=1;
		}
	}
	long long ans=0;
	for(int i=0;i<=29;i++){
		if(b[i]==1){
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
}
