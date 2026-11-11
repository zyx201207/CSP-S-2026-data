#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans,c,bans;
bool yj;
struct ejz{
	int num;
	bool w[32];
}cnt[200100];
void turn(int num,bool w[32]){
	for(int i=30;i>=0;i--){
		if(num-pow(2,i)>=0){
			w[i]=true;
			num-=pow(2,i);
		}
	}
}
bool cmp(ejz a,ejz b){
	for(int i=30;i>=0;i--){
		if(a.w[i]>b.w[i]) return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i].num=a[i];
		turn(a[i],cnt[i].w);
	}
	sort(cnt+1,cnt+n+1,cmp);
	for(int i=30;i>=0;i--){
		c=0;
		for(int j=1;j<=n;j++){
			if(cnt[j].w[i]) c++;
		}
		if(c==m){
			int q=0;
			for(int j=1;j<=n;j++){
				if(cnt[j].w[i] && q==0){
					ans=cnt[j].num;
					q++;
				}
				if(cnt[j].w[i] && q!=0){
					ans=ans&cnt[j].num;
				}
			}
			break;
		}
		if(c>m){
			n=c;
			yj=true;
		}
	}
	if(yj){
		int q=0;
		for(int i=1;i<=m;i++){
			if(q==0){
				bans=cnt[i].num;
				q++;
			}
			if(q!=0){
				bans=bans&cnt[i].num;
			}
		}
	}
	cout<<max(ans,bans);
	return 0;
}