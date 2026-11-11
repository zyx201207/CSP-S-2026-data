#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
long long c[N];
bool boo=0;
bool booo=0;
long long pxjh(int y,int x){
	long long ans=0;
	int j=y;
	for(int i=1;i<=x;i++){
		ans+=a[j]*i;
		j++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	if(a[1]!=1||a[2]!=2){
		boo=1;
	}
	long long qq=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			boo=1;
		}
		if(a[i]-a[i-1]!=qq){
			booo=1;
		}
	}
	if(!boo){
		int dq1=0;
		for(int i=1;i<=n;i++){
			if(2*m>=i*i+i){
				dq1=i;
			}
		}
		cout<<dq1+1<<endl;
		return 0;
	}
	if(!booo){
		int dq1=0;
		for(int i=1;i<=n;i++){
			if(2*m>=qq*i+qq*i*i){
				dq1=i;
			}
		}
		cout<<dq1+1<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	int d1=0;
	for(int j=1;j<n;j++){
		int px=0;
		for(int i=1;i<=n;i++){
			px=pxjh(j,i);
			if(m<px){
				break;
			}
			if(i>d1){
				d1=i;
			}
		}
		
	}
	cout<<d1+1<<endl;
	return 0;
}
//7199
//¿ªfreopen!!! 
