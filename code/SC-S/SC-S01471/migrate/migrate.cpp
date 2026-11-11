#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10;
int n,d,x[N],pos[N],f[N][6];
inline int getval(int cnt1,int cnt2,int cnt3){
/*
0.  0 0 1
1.  0 1 1
2.  1 1 1
3.  0 2 1
4.  0 0 2
5.  0 1 2
*/
	if(cnt1==1&&cnt2==0&&cnt3==0)return 0;
	if(cnt1==1&&cnt2==1&&cnt3==0)return 1;
	if(cnt1==1&&cnt2==1&&cnt3==1)return 2;
	if(cnt1==1&&cnt2==2&&cnt3==0)return 3;
	if(cnt1==2&&cnt2==0&&cnt3==0)return 4;
	return 5;
}
inline int trans(int i,int j){
	if(i==pos[i])return 0;
	if((j==1||j==3||j==5)&&(i==1))return 0;
	if((j==2)&&(i<=2))return 0;
	int c1,c2,c3;
	if(!j)c1=1,c2=c3=0;
	else if(j==1)c1=c2=1,c3=0;
	else if(j==2)c1=c2=c3=1;
	else if(j==3)c1=1,c2=2,c3=0;
	else if(j==4)c1=2,c2=c3=0;
	else c1=2,c2=1,c3=0;
	int cnt1=0,cnt2=0,cnt3=0;
	if(x[pos[i]]-x[i]<=d)cnt1+=c1;
	if(c2&&x[pos[i]]-x[i-1]<=d)cnt1+=c2;
	if(c3&&x[pos[i]]-x[i-2]<=d)cnt1+=c3;
	if(pos[i]-1>i&&x[pos[i]-1]-x[i]<=d)cnt2+=c1;
	if(pos[i]-1>i&&c2&&x[pos[i]-1]-x[i-1]<=d)cnt2+=c2;
	if(pos[i]-1>i&&c3&&x[pos[i]-1]-x[i-2]<=d)cnt2+=c3;
	if(pos[i]-2>i&&x[pos[i]-2]-x[i]<=d)cnt3+=c1;
	if(pos[i]-2>i&&c2&&x[pos[i]-2]-x[i-1]<=d)cnt3+=c2;
	if(pos[i]-2>i&&c3&&x[pos[i]-2]-x[i-2]<=d)cnt3+=c3;
	cnt1=min(cnt1,3ll);
	cnt2=min(cnt2,3ll-cnt1);
	cnt3=min(cnt3,3ll-cnt1-cnt2);
	if(cnt1==3)return 0;
	int val=f[pos[i]][getval(cnt1,cnt2,cnt3)];
	int l=i+1,r=pos[i];
	while(l<=r){
	  int mid=(l+r)>>1,cnt=0;
	  if(x[mid]-x[i]<=d)cnt+=c1;
	  if(c2&&x[mid]-x[i-1]<=d)cnt+=c2;
	  if(c3&&x[mid]-x[i-2]<=d)cnt+=c3;
	  if(cnt==1)r=mid-1;
	  else l=mid+1;
	}
	int p1=l;
	l=i+1,r=p1-1;
	while(l<=r){
	  int mid=(l+r)>>1,cnt=0;
	  if(x[mid]-x[i]<=d)cnt+=c1;
	  if(c2&&x[mid]-x[i-1]<=d)cnt+=c2;
	  if(c3&&x[mid]-x[i-2]<=d)cnt+=c3;
	  if(cnt==2)r=mid-1;
	  else l=mid+1;
	}
	val+=p1-l;
	return val;
}
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	for(int i=n,p=n;i>=1;--i){
	  while(x[p]-x[i]>d)--p;
	  pos[i]=p;
	}
	for(int i=n;i>=1;--i){
	  for(int j=0;j<6;++j)
		f[i][j]=trans(i,j);
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans+=f[i][0];
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
/*

从前往后跳，我们只在乎跳到的这个点和它左边 O(1) 个点有多少种方案。

具体要算这几种情况的答案。

0.  0 0 1
1.  0 1 1
2.  1 1 1
3.  0 2 1
4.  0 0 2
5.  0 1 2
*/