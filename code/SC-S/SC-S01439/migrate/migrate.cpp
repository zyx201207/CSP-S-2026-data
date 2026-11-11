#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int to[N];
int a[N];
int dis[N],f[N]; // 表示走到 i 的最短路径和方案数
int c[N];
void sol(){
	int n,d; cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&a[j]-a[i]<=d) j++;
		to[i]=j-1; //cout<<to[i]<<" ";
	}
	int ans=0;
	for(int i=1;i<=n;i++){ // 起点
		vector<int> D;
		D.push_back(i-1);
		D.push_back(i);
		int u=i;
		while(to[u]>u) u=to[u],D.push_back(u);
//		cout<<D.size()<<" ";
		for(int j=i;j<=u;j++) f[j]=0;
		int s=1;
		for(int j=1;j<D.size();j++){
			
			int l=D[j-1]+1,r=D[j],ns=0; //[l,r]
//			cout<<l<<" "<<r<<"\n";
			for(int k=l;k<=r;k++){
				if(s==2) ans++;
//				cout<<s<<"\n";
				if(to[k]>r) ns+=s,f[to[k]]+=s;
				s-=f[k];
				
			}
			s=ns;
		}
		
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--) sol();
	return 0;
}
// 分离 dis 和 cnt
// 目前 N^3 ，加油！
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int to[N];
int a[N];
void sol(){
int n,d; cin>>n>>d;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1,j=1;i<=n;i++){
while(j<=n&&a[j]-a[i]<=d) j++;
to[i]=j-1; //cout<<to[i]<<" ";
}
//	cout<<"\n";
int ans=0;
for(int i=1;i<=n;i++) if(to[i]>i){ // 起点在 i
int u=i;
int hav=0;
while(u<=n){
u=to[u]; // 当前结束点
// 作为有了的结束点
if(hav) ans++;
// 作为最后一个路径点，下一个小于 to_u
// <=to_{u-1}
// 同时大于 to_{u-2}
if(u-2>=i){
int mn=min(to[u-1],to[u]-1);
int mx=max(to[u-2],u);
if(mn>mx) ans+=mn-mx;
//				cout<<u<<" ";
}
// 作为延伸点
if(u==n||to[u]==u) break; // 无法延申
if(to[u]==to[u-1]){
if(hav) break;
if(to[u-2]==to[u]) break; // 无法延申
hav=1;
}

}
//		cout<<ans<<" ";
}
cout<<ans<<"\n";
}
signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0);
int c,t; cin>>c>>t;
while(t--) sol();
return 0;
}
// 目前 N^2 ，加油！
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int to[N];
int a[N];
int f[2][N]; // 有多少 hav=0 de hav=1 的
void sol(){
int n,d; cin>>n>>d;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1,j=1;i<=n;i++){
while(j<=n&&a[j]-a[i]<=d) j++;
to[i]=j-1,f[0][i]=f[1][i]=0; cout<<to[i]<<" ";
}

int ans=0;
for(int i=1;i<=n;i++){
// 之前传递的
ans+=f[1][i]; // 作为有了的结束点
if(i>2){ // 作为最后路径点
int mn=min(to[i-1],to[i]-1);
int mx=max(to[i-2],i);
if(mn>mx) ans+=(mn-mx)*f[0][i];
}
// 作为延伸点
if(to[i]>i){
if(to[i]==to[i-1]){
if(to[i-2]!=to[i])
f[1][to[i]]+=f[0][i];
}
else{
f[0][to[i]]+=f[0][i],
f[1][to[i]]+=f[1][i];
}

}


if(to[i]>i){ // 起点在 i
//			cout<<ans<<" ";
int u=i;
int hav=0;
while(u<=n){
u=to[u]; // 当前结束点
if(u-2>=i){
f[hav][u]++;
//					cout<<i<<" "<<hav<<" "<<u<<"\n";
break;
}
// 作为有了的结束点
if(hav) ans++;
// 作为最后一个路径点，下一个小于 to_u
// <=to_{u-1}
// 同时大于 to_{u-2}
if(u-2>=i){ // 人工跳到 to_{u-2}>=i
int mn=min(to[u-1],to[u]-1);
int mx=max(to[u-2],u);
if(mn>mx) ans+=mn-mx;
//				cout<<u<<" ";
}
// 作为延伸点
if(u==n||to[u]==u) break; // 无法延申
if(to[u]==to[u-1]){
if(hav) break;
if(to[u-2]==to[u]) break; // 无法延申
hav=1;
}

}
//		cout<<ans<<"\n";
}
}
cout<<ans<<"\n";
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0);
int c,t; cin>>c>>t;
while(t--) sol();
return 0;
}
// 目前 N^2 ，加油！

*/