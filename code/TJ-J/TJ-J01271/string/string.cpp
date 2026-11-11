#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[200005][2];
char b[200005][2];
long long c;
long iop=0,qwe=0;
long long i=0;
int ai=1,bi=1,n=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int o=1;o<=n;o++){
		cin>>a[o][0]>>b[o][0];
		a[n-o+1][1]=a[o][0];
		b[n-o+1][1]=b[o][0];
		iop+=a[o][0];
	}
//	cout<<iop/2;
//	cout<<"&";
	do{
		qwe+=1;
//		cout<<qwe;
		if(a[ai][0]<=0){
			ai+=1;
		}
		if(a[bi][1]<=0){
			bi+=1;
		}
		if(qwe>iop/2){
			return 0;
		}
		c=min(a[ai][0],a[bi][1]);
		if(b[ai][0]!=b[bi][1]){
			i+=c;
//			cout<<i;
		}
		
		a[bi][1]-=c;
		a[ai][0]-=c;
	}while(true);
	cout<<i;
	return 0;
}
