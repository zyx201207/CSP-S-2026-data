#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int ern[35]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,23554432,47108864,94217728,188435456,376870912};
int xmm=0,cnt=0;
int a[N];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++) {
			if(a[i]==ern[j]-1){
				cnt++;
				if(a[i]>=xmm) xmm=a[i];
			} 
		}	
	}
	sort(a+1,a+1+n,cmp);
	if(cnt%2==1) cout<<xmm;
	else cout<<a[n-1];
	return 0; 
} 
