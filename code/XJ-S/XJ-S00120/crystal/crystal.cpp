#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans,c[N];
void check(int idx){
	int len=0;
	int cntma=0,cntmi=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=idx){
			cntmi++;
			c[++len]=abs(idx-a[i]);
		}
	}
	sort(c+1,c+1+len);
	int cnt=0,sum=0;
	for(int i=1;i<=len;i++){
		if(sum+c[i]>m){
			ans=max(ans,cnt); 
			break;
		}else if(sum+c[i]<m){
			sum+=c[i];
			cnt++;
			ans=max(ans,cnt);
		}else{
			ans=max(ans,cnt+1);
		}
	}

}

void solve(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i]>m){
			break;
		}else if(sum+a[i]<m){
			sum+=a[i];
			ans++;
			
		}else{
			ans=ans+1;
			break;
		}
	}
	cout<<ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1,cha=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			cha=a[2]-a[1];
		}else if(i>2&&a[i]-a[i-1]!=cha){
			flag=0;
		}
	}
	if(flag){
		solve();
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		check(i);
	}
	cout<<ans;
	return 0;
} /*

5 5
1 2 4 8 9

5 10000
-3 -1 2 2 7

5 200
1 3 5 7 9

kqq100525
*/
