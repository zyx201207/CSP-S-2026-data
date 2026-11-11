#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool b[200001];
int n,m;
long long maa=-1;
void lo(long long js,int dp){
	if(dp==m){
		if(maa<js) maa=js;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(js==0 && dp==0) lo(a[i],dp+1);
			else lo(js&a[i],dp+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	lo(0,0);
	cout<<maa;
}
