#include<bits/stdc++.h>
using namespace std;
const int MAXN=500009;
int a[MAXN],d[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,cnt=0;
	long long m;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long lastsum=0,temp;
	int tempr=1,tempcnt=1;
	for(int l=1;l<n;l++){
		long long tempvar=m-lastsum;
		for(int r=tempr+1;r<=n;r++){
			temp=(long long)d[r] * (long long)(r-l);
			lastsum+=temp;
			tempvar-=temp;
			tempcnt++;
			if(tempvar<0){
				tempcnt--;
				if(tempcnt>cnt) cnt=tempcnt;
				tempr=r;
				lastsum-=a[r]-a[l];
				break;
			}
		} 
	}
	cout<<cnt;
	return 0;
}

