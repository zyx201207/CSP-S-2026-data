#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int cmpky;
bool cmp(int x,int y){
	int xx=x&((1<<cmpky)-1);
	int yy=y&((1<<cmpky)-1);
	return xx>yy;
}
signed main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);


	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int len=0,maxans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(maxans<a[i]){
			len++;
			maxans=(maxans<<1)+1;
		}
	}
	int maxone=0;
	for(int i=len;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n&&cnt<m;j++){
			cnt+=a[j]&(1<<(i-1));
		}
		if(cnt>=m){
			maxone=i;
			break;
		}
	}
	
	if(maxone==0||maxone==1){
		cout<<maxone;
		return 0;
	}
	
	cmpky=maxone-1;
	sort(a+1,a+n+1,cmp);
	int nowlen=n;
	for(int i=maxone-1;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=nowlen;j++){
			if(a[j]&(1<<(i-1))){
				cnt++;
			}else{
				break;
			}
		}
		if(i!=1){
			cmpky=i-1;
			sort(a+1,a+cnt+1,cmp);
			nowlen=max(m,cnt);
			if(nowlen>cnt){
				sort(a+cnt+1,a+nowlen+1,cmp);
			}
		}
		
	}
	int ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
