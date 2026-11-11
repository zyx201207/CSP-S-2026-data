#include<bits/stdc++.h>
using namespace std;
#define PID "string"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const long long N=2e5+10;
long long n,a[N],c[N],ans;
char b;
int main(){
	FI;FO;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		c[i]=b-'a'+1;
	}
	long long l=1,r=n;
	int ls=a[l],rs=a[r];
	while(l<r){
		if(c[l]==c[r]){
			if(ls<rs){
				rs-=ls;
				l++;
				ls=a[l];
			}else if(ls==rs){
				l++;
				r--;
				ls=a[l];rs=a[r];
			}else{
				ls-=rs;
				r--;
				rs=a[r];
			}
		}else{
			if(ls<rs){
				rs-=ls;
				ans+=ls;
				l++;
				ls=a[l];
			}else if(ls==rs){
				ans+=ls;
				l++;
				r--;
				ls=a[l];rs=a[r];
			}else{
				ls-=rs;
				ans+=rs;
				r--;
				rs=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
