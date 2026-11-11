#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005];//60pts
int an=INT_MIN;//kaolv dp
void dfs(int id,int used,int cnt){
	if(used==m){
		an=max(an,cnt);
		return;
	}
	if(id>=n){
		return;
	}
	for(int i=id+1;i<n;i++){
		dfs(i,used+1,cnt&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int yy=INT_MIN;
for(int i=0;i<n;i++){
	cin>>a[i];
	yy=max(yy,a[i]);
}
if(n<=20){
	for(int i=0;i<n;i++){
		dfs(i,1,a[i]);
	}
	cout<<an;
}else if(m==1){
	int ma=INT_MIN;
	for(int i=0;i<n;i++){
		ma=max(ma,a[i]);
	}
	cout<<ma;
}else if(m==2){
	int ma=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ma=max(ma,a[i]&a[j]);
		}
	}
	cout<<ma;
}else if(m==n){
	int ans=a[0];
	for(int i=1;i<n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}else if(yy<4){//0 1 2 3
	int c[4]={0,0,0,0};
	for(int i=0;i<n;i++){
		c[a[i]]++;
	}
	if(c[3]>=m){
		cout<<3;
	}else if(c[3]+c[2]>=m){
		cout<<2;
	}else if(c[3]+c[1]>=m){
		cout<<1;
	}else{
		cout<<0;
	}
}else if(m==n-1){
	int ma=INT_MIN;
	for(int i=0;i<n;i++){
		if(i==0){
			int ans=a[1];
			for(int i=2;i<n;i++){
				ans=ans&a[i];
			}
			ma=max(ma,ans);
		}else{
			int ans=a[0];
			for(int j=1;j<n;j++){
				if(j!=i){
					ans=ans&a[i];
				}
			}
			ma=max(ma,ans);
		}
	}
	cout<<ma;
}
	return 0;
}//CSP 2026 RP++
//CSP 2026 RP++
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
