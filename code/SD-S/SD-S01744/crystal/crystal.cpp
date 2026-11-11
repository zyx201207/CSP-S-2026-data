#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+10;
int n,m;
int num[N],d[N];
bool cmp(int a,int b){
	return a<b;
}
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		num[i]=read();
	}
	sort(num+1,num+n+1,cmp);
	int f_m=m;
	int r=n;
	int fak_ans=0;
	for(int i=n;i>=1;i--){
		if(f_m>=num[r]-num[i]){
			fak_ans++;
			f_m-=(num[r]-num[i]);
		}
		else{
			while(f_m<num[r]-num[i]&&r>=1){
				fak_ans--;
				f_m+=fak_ans*(num[r]-num[r-1]);
				r--;
			}
			if(f_m>=num[r]-num[i]){
				fak_ans++;
				f_m-=(num[r]-num[i]);
			}
				
		}
		ans=max(ans,fak_ans);
	}
	cout<<ans;
	return 0;
}
