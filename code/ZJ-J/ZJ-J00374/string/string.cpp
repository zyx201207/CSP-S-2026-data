#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,sum=0,ans=0;
struct node{int x;char y;};
node a[200010];
signed main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		sum+=a[i].x;
	}
	long long cnt=0;
	for(i=1;i<=n;i++){
		cnt+=a[i].x;
		if(cnt>sum/2){
			long long rex=cnt-a[i].x;
			long long pos1=sum/2-rex;
			long long pos2=a[i].x-pos1-(sum&1);
			char ch=a[i].y;a[i].x=pos1;
			for(j=i+1;j<=n+1;j++){
				long long tempx=a[j].x;
				char tempy=a[j].y;
				a[j].x=pos2;a[j].y=ch;
				pos2=tempx;ch=tempy;
			}break;
		}
	}n++;sum-=(sum&1);
	int l=1,r=n,le=0,re=sum;
	while(le<re){
		if(a[l].x>a[r].x){
			if(a[l].y!=a[r].y)ans+=a[r].x;
			le+=a[r].x;re-=a[r].x;
			a[l].x-=a[r].x;r--;
		}else if(a[l].x<a[r].x){
			if(a[l].y!=a[r].y)ans+=a[l].x;
			le+=a[l].x;re-=a[l].x;
			a[r].x-=a[l].x;l++;
		}else{
			if(a[l].y!=a[r].y)ans+=a[l].x;
			le+=a[l].x;re-=a[r].x;
			a[r].x-=a[l].x;a[l].x=0;
			l++;r--;	
		}
	}
	cout<<ans<<endl;
	return 0;
}
