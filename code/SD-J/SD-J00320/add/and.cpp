#include<bits/stdc++.h>
using namespace std;
long long a[200005][2];
long long b[200005];
long long mx=0,x;
int ans[105];
bool cmp(long long x,long long y){
	return x>y;
}
long long biao[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1.04858e+006,2.09715e+006,4.1943e+006,8.38861e+006,1.67772e+007,3.35544e+007,6.71089e+007,1.34218e+008,2.68435e+008,5.36871e+008,1.07374e+009};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0];
		if(mx<a[i][0]){
			mx=a[i][0];
			x=i;
		}
		for(int j=0;j<=30;j++){
			if(a[i][0]>biao[j]){
				a[i][1]=j;
				ans[a[i][1]]++;
			}
		}
		
	}
	if(m==1) {
		cout<<mx;
		return 0;
	}
	int f; 
	for(int i=30;i>=0;i--){
		if(ans[i]>=m) {
			f=i;
			break;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i][1]>=f){
			if(a[i][1]>f){
				for(int j=a[i][1];j>f;j--){
					if(a[i][0]>biao[f+1]);
						a[i][0]-=biao[j];
					
				}
			}
			b[sum++]=a[i][0];
		}
	}
	sort(b,b+sum,cmp);
	sum--;
	int zzz=0;
	for(int i=0;i<=sum-m;i++){
		int z=b[i];
		for(int j=i;j<i+m;j++){
			int t=b[j];
			z&=t;
		}
		if(z>zzz) zzz=z;
	}
	if(zzz==0) zzz=1;
	cout<<zzz;
	return 0;
}
