#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
long long len;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=0,r=len+1;
	long long mid=len/2ll;
	int cntl=1,cntr=n;
	while(l<mid){
		long long dl;
		if(l+a[cntl]>mid){
			dl=mid-l;
			l=mid;
		}
		else{
			dl=a[cntl]; 
			l+=a[cntl];
		}
		long long dth=r-dl;
		while(r>dth){
			long long dr;
			bool vis=false;
			if(r-a[cntr]<dth){
				dr=r-dth;
				a[cntr]-=dr;
				r=dth;
				vis=true; 
			}
			else{
				r-=a[cntr];
				dr=a[cntr];
			}
			if(c[cntl]!=c[cntr]){
				ans+=dr; 
			}
			cntr--;
			if(vis){
				cntr++;
			}
		}
		cntl++;
	}
	cout<<ans;
	return 0;
} 
