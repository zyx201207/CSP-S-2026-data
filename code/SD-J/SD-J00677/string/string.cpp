#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int cnt;
	char x;
};
node p[1010101],a[1010101];
int lin;
void xg1(int res,int i){
	for(int j=i+1;j<=lin;j++){
		if(res>a[j].cnt){
			res-=a[j].cnt;
			a[j].cnt=0;
		}else{
			a[j].cnt-=res;
			break;
		}
	}
}
void xg2(int res,int pos){
	for(int j=pos;j>=1;j--){
		if(res>a[j].cnt){
			res-=a[j].cnt;
			a[j].cnt=0;
		}else{
			a[j].cnt-=res;
			break;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >>n;
	int qq=-1e18;
	for(int i=1;i<=n;i++){
		cin >>p[i].cnt>>p[i].x;
		qq=max(qq,p[i].cnt);
	}
	if(n*qq<30000000){
	//	cout <<"Here\n";
		string s;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p[i].cnt;j++){
				s.push_back(p[i].x);
			}
		}
		for(int i=0;i<s.size();i++){
			int pos=s.size()-i-1;
			if(s[i]!=s[pos]){
				ans++;
				s[pos]=s[i];
			}
		}
		cout <<ans;
		return 0;
	}else{
		for(int i=1;i<=n;){
			int len=p[i].cnt,res=1;
			while(p[i].x==p[i+res].x){
				len+=p[i+res].cnt;
				res++;
			}
			a[++lin].cnt=len;
			a[lin].x=p[i].x;
			i+=res;
		}
		int ans=0;
		for(int i=1;i<=lin/2;i++){
			int pos=lin-i+1;
			if(a[pos].cnt<=0&&a[i].cnt<=0) continue;
			if(a[pos].cnt<=0){
				ans+=a[i].cnt;
				continue;
			}else if(a[i].cnt<=0){
				ans+=a[pos].cnt;
				continue;
			}
			if(a[i].x!=a[pos].x){
				if(a[i].cnt<a[pos].cnt){
					ans+=a[pos].cnt;
					xg1(a[pos].cnt-a[i].cnt,i);
				}else{
					ans+=a[i].cnt;
					xg2(a[i].cnt-a[pos].cnt,pos);
				}
			}else if(a[i].cnt<a[pos].cnt){
				ans+=(a[pos].cnt-a[i].cnt);
				int res=(a[pos].cnt-a[i].cnt);
				xg1(res,i);
			}else if(a[i].cnt>a[pos].cnt){
				ans+=(a[i].cnt-a[pos].cnt);
				int res=(a[i].cnt-a[pos].cnt);
				xg2(res,pos);
			}
		}
		cout <<ans;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
