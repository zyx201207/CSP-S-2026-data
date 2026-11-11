#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000001],zuo[2000001],you[2000001],vis[5001];
int sou(int x,int y){
	int minn=0,mcnt=0;
	for(int i=x;i<y;i=you[i]){
		minn++;
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==y){
			if(vis[now]==minn)mcnt++;
			if(mcnt>2)return 3;
		}
		for(int i=now+1;i<=you[now];i++){
			if(vis[i]!=0&&vis[now]+1>vis[i])continue;
			vis[i]=vis[now]+1;
			q.push(i);
		}
	}
	return mcnt;
}
int check(int x,int y){
	if(a[y]-a[x]<=d)return 0;
	if(y-x<=2)return 0;
	if(a[y]-a[x]<=2*d){ 
		if(you[x]-zuo[y]==1)return 1;
		else return 0;
	}
	return (sou(x,y)==2);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			long long cha=a[2]-a[1];
			long long k=d/cha;
			if(k<2)cout<<0<<endl;
			else cout<<max(n-(2*k-1),0ll)<<endl;
			continue;
		}
		long long l=1,r=0,now=0,ans=0;
		while(r<n){
			r++;
			now=a[r]-a[l];
			while(now>d){
				now=a[r]-a[l+1];
				you[l]=r-1;
				l++;
			}
			zuo[r]=l;
			you[l]=r;
		}
		for(;l<=n;l++){
			you[l]=n;
		}
		if(c==13||c==14){
			long long ans=0;
			for(int i=1;i<=n;i++){
				int l=i,r=n+1,mid;
				while(l+1<r){
					mid=(l+r)/2;
					if(you[i]-zuo[mid]<2)l=mid;
					else r=mid;
				}
				int ll=i,rr=n+1;
				while(l+1<r){
					mid=(ll+rr)/2;
					if(you[i]-zuo[mid]<=2)ll=mid;
					else rr=mid;
				}
				ans+=ll-l;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=5000){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[j-1]>d)break;
					ans+=check(i,j);
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
}
