#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n;
int a1[N];
char c1[N],c2[N];
int a2[N];
int sum=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a1[i]>>c1[i],sum+=a1[i];
	for(int i=1;i<=n;i++) a2[i]=a1[n-i+1],c2[i]=c1[n-i+1];
	int zhongdian=(sum+1)/2;
	int p=1;
	int fzhongdian=zhongdian;
	while(fzhongdian>0) fzhongdian-=a1[p],p++;
	p--;
	int q=1,qsum=0,ans;
	char pre;
	int preint;
	for(int i=1;i<=p;i++){
		qsum+=a1[i];
		if(qsum>zhongdian) a1[i]-=abs(qsum-zhongdian);
		int mubiao=a1[i];
		char mubiaoc=c1[i];
		if(preint!=0){
			mubiao-=preint;
			if(mubiaoc!=pre) ans+=preint;
		}
		while(mubiao>0){
			mubiao-=a2[q]; 
			if(c2[q]!=mubiaoc) ans+=a2[q];
			q++;
		}
		if(mubiao<0){
			pre=c2[i];
			ans+=mubiao;
			preint=mubiao+a2[q-1];
		}
	}
	cout<<ans;
	return 0;
}
