#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int n,m;
int a[N]; 
struct node{
	int id;
	int pl;
}tong[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}int max(int _,int __){
	return _>__?_:__;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int flag=a[2]-a[1];
	bool fl=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=flag){
			fl=0;
			break;
		}
	}if(fl==1){
		if(flag==0) cout<<n;
		else{
			m/=flag;
			int l=1,r=1e9;
			int ans=0;
			while(l<=r){
				int mid=l+r>>1;
				if(mid*(mid+1)/2<=m){
					ans=mid;
					l=mid+1;
				}else r=mid-1;
			}cout<<ans+1;
		}return 0;
	}else{
		sort(a+1,a+n+1);
		int ans=1;
		for(int i=1;i<=n;i++){
			int sumpl=1;
			int M=m;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=M){
					sumpl++;
					M=M-a[i]+a[j];
				}else break;
			}ans=max(ans,sumpl);
		}cout<<ans;
	}
	return 0;
}
/*

5 5
2 2 4 8 9
0 2 4 1



*/
