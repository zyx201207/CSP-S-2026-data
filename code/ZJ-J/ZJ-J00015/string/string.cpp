#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int n,a[320001],b[320001];
char c[320001],d[320001];
int f1[320001],f2[320001];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],b[n-i+1]=a[i],d[n-i+1]=c[i];
	for(int i=1;i<=n;i++)
		f1[i]=f1[i-1]+a[i],f2[i]=f2[i-1]+b[i];
	int now1=1,now2=1,now=0;
	//now:first i [ge] done
	while(now<f1[n]){
		if(f1[now1]<=f2[now2]){
			if(c[now1]!=d[now2]){
				ans+=(f1[now1]-now);
			}
			now=f1[now1];
			now1++;
			if(f1[now1-1]==f2[now2])now2++;
		}
		else{
			if(c[now1]!=d[now2]){
				ans+=(f2[now2]-now);
			}
			now=f2[now2];
			now2++;
		}
	}
	cout<<ans/2;
	return 0;
}