#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
ll cnt=0;
int x[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	int l=0,r=n+1;
	char lcf=' ',rcf=' ';
	ll lxf=0,rxf=0;
	while(l<r){
		if(!lxf){
			l++;
			lcf=c[l];
			lxf=x[l];
		}
		if(!rxf){
			r--;
			rcf=c[r];
			rxf=x[r];
		}
		if(lcf!=rcf){
			if(lxf>rxf){
				cnt=cnt+lxf-rxf;
				lxf-=rxf;
				rxf=0;
			}if(lxf<rxf){
				cnt=cnt+rxf-lxf;
				rxf-=lxf;
				lxf=0;
			}if(lxf==rxf){
				cnt+=lxf;
				lxf=0;
				rxf=0;
			}
		}else{
			if(lxf>rxf){
				lxf-=rxf;
				rxf=0;
			}if(lxf<rxf){
				rxf-=lxf;
				lxf=0;
			}if(lxf==rxf){
				lxf=0;
				rxf=0;
			}
		}
		if(l+1==r) break;
	}
	cout<<cnt;
	return 0;
}
