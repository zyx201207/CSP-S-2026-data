#include<bits/stdc++.h>
using namespace std;
#define int long long
struct bin{
	int d[31],val;
}a[200001];
bool cmp(const bin &x,const bin &y){
	return x.val>y.val;
}
int n,m,dig,ans,pos;
int cnt[31];
int pw2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
void upd(int i){
	for(int j=pos;j<=n;j++){
		if(a[j].d[i]){
			pos=j;
			break;
		}
	}
	for(int j=i;j>=0;j--){
		cnt[j]=0;
	}
	for(int j=pos;a[j].d[i]&&(j<=n);j++){
		for(int k=i;k>=0;k--){
			if(a[j].d[k]){
				cnt[k]++;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].val=x;
		for(int j=30;j>=0;j--){
			if(pw2[j]<=x){
				x-=pw2[j];
				a[i].d[j]=1;
				cnt[j]++;
			}
			if(x==0){
				break;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			dig=i;
			upd(i-1);
			break;
		}
		else{
			cnt[i]=0;
		}
	}
	ans+=pw2[dig];
	for(int i=dig-1;i>=0;i--){
		if(cnt[i]>=m){
			ans+=pw2[i];
			upd(i);
		}
		else{
			cnt[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
In front of you is T3, the most important part of this exam.
If AC T3 you can get 300pts so try hard.
Oh T3 is a little difficult I have to think for a while qwq
So now I have to complete T3 in an hour...
this is awful!
T3 cant AC...
*/
