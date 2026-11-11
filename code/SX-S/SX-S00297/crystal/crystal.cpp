#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n;
long long m,mm,cnt,x,y;
long long t1,t2,t3;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	mm=m;
	for(int i=1;i<=n;i++){
		cin>>y;
		a[i]=y;
		if(i==1) t1=y;
		else if(i==2) t2=y;
		else if(i==3) t3=y;
		else t1=t2,t2=t3,t3=y;
		if(i>=3 && t3-t2!=t2-t1) f=false;
		long long c=abs(y-x)*(i-1);
		if(mm-c>=0){
			cnt=i;
			mm-=c;
			x=y;
		}
	}
	if(f){
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	long long sum;
	int k=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<i;j++){
			sum+=a[i]-a[j];
		}
		if(sum<=m){
			k=i;
		}
	}
	cout<<k;
	return 0;
}