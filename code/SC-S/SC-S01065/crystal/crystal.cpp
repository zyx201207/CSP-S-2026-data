#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[2000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maa=0;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		b[a[j]]++;
		maa=max(maa,a[j]);
	}
	long long ma1=0,ma=0;
	for(int i=1;i<=n;i++){
		ma1=max(ma1,b[i]);
	}
	int ma2=ma1;
	for(int i=1;i<=n;i++){
		if(b[i]==ma1){
			ma1=0;
			continue;
		}
		ma=max(ma,b[i]);
	}
	cout<<ma2+ma+1;
	return 0;
}
