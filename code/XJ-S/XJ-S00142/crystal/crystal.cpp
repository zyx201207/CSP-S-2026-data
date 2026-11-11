#include<bits/stdc++.h>
using namespace std;
long long st[1000000];
long long b[1000000],c[1000000],d[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,a=0,t=1,o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st[i];
	}
	sort(st+1,st+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+st[i];
		d[i]=st[i]*t;
		//cout<<t<<' '<<b[i]<<' '<<d[i]<<endl;
		if(d[i]-b[i]-m>0){
			if(d[i]-b[i]-d[i-2]-m<0){
				t=2;
				b[i]-=b[i-2];
			}
			else{
				t=1;
				b[i]-=b[i-1];
			}
		}if(t>o){
			o=t;
		}
		//cout<<t<<endl;
		t++;
	}
	cout<<o;
	return 0;
}

