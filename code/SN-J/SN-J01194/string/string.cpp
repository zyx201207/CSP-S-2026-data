#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long xx,yy,cnt=0;char xc,yc;
	xx=a[1],yy=a[n],xc=c[1],yc=c[n];
	for(int i=1,j=n;i<=j;){
		if(xc==yc){
			if(xx<yy){
				yy=yy-xx;
				xc=c[i+1];
				xx=a[i+1];
				i++;
			}else if(xx>yy){
				xx=xx-yy;
				yc=c[j-1];
				yy=a[j-1];
				j--;
			}else{
				xc=c[i+1];
				xx=a[i+1];
				yc=c[j-1];
				yy=a[j-1];
				i++,j--;
			}
		}else {
			if(xx<yy){
				cnt+=xx;
				yy=yy-xx;
				xc=c[i+1];
				xx=a[i+1];
				i++;
//				cout<<cnt<<" ";
			}else if(xx>yy){
				cnt+=yy;
				xx=xx-yy;
				yc=c[j-1];
				yy=a[j-1];
				j--;
//				cout<<cnt<<" ";
			}else{
				cnt+=xx;
				xc=c[i+1];
				xx=a[i+1];
				yc=c[j-1];
				yy=a[j-1];
				i++,j--;
//				cout<<cnt<<" ";
			}
		}
	}
	cout<<cnt;
	
	
	return 0;
}
