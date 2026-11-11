#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
struct num{
	int x[35],y,weishu;
}b[200005];
void to(int f,int st){
	int g=f,yy=0,ss=1;
	while(g){
		yy++;
		g/=2;
	}
	b[st].weishu=yy;
	while(f){
		b[st].x[ss]=f%2;
		f/=2;
		ss++;
	}
	return ;
}
bool cmp(num aa,num bb){
	if(aa.y!=bb.y){
		return aa.y>bb.y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i].y;
		to(b[i].y,i);
	}
	sort(b+1,b+1+n,cmp);
	for(int j=30;j>=1;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i].weishu<j){
				break;
			}
			if(b[i].x[j]==1){
				cnt++;
				if(cnt==1){
					ans=b[i].y;
				}
				else{
					ans=ans&b[i].y;
				}
			}
			if(cnt==m){
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
