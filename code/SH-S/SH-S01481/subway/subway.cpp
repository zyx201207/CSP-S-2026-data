#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,a[1000005],s[100005];
struct f{
	long long x,y;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	f b[100005][5];
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			cin>>b[j][i].x>>b[j][i].y;
		}
	}
	for(int q=1;q<=p;q++){
		long long r,l,ans=0,h=0;
		cin>>l>>r;
		if(n==1){
			for(int i=1;i<=s[1];i++){
				if(b[i][1].x==l){
					ans+=a[l];
					h=1;
				}
				if(h==1){
					ans+=b[i][1].y;
				}
				if(b[i][1].x==r){
					h=0;
					ans+=a[r];
				}
			}
			cout<<ans;
		}
	}
	return 0;
}

