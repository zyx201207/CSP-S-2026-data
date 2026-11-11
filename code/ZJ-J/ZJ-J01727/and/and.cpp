#include<bits/stdc++.h>
#define int long long
using namespace std;
bool flag=0;
int n,m,maxn=-1;
int a[200005];
string s;
void dfs(int now,int ans,int num){
	if(num==m){
		maxn=max(maxn,ans);
		return;
	}
	if(m-num>n-now+1||now==n+1){
		return;
	}
	if(num==0){
		dfs(now+1,a[now],num+1);
		dfs(now+1,0,num);
	}
	else{
		dfs(now+1,ans&a[now],num+1);
		dfs(now+1,ans,num);	
	}
	return;
}
int and2(int x){
	string nowq;
	string kkk;
	int bei=x,ans=1;
	if(x==0){
		kkk+="0";
	}
	else{
		while(ans<bei){
			ans*=2;
		}
		if(ans!=bei){
			ans/=2;
		}
		while(ans!=0){
			if(bei<ans){
				nowq+="0";
				ans/=2;
				continue;
			}
			nowq+="1";
			bei-=ans;
			ans/=2;
		}
	}
	for(int i=0;i<s.size();i++){
		if(i>=nowq.size()&&s[i]=='0'){
			kkk+="1";
			continue;
		}
		if(i>=nowq.size()&&s[i]=='1'){
			kkk+="0";
			continue;
		}
		if(nowq[i]==s[i]){
			kkk+="1";
			continue;
		}
		kkk+="0";
	}
	int qqf=0,nb=1;
	for(int i=kkk.size()-1;i>=0;i--){
		qqf+=nb*(kkk[i]-'0');
		nb*=2;
	}
	return qqf;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			flag=1;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n-1){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		int bei=maxn,ans=1;
		if(bei==0){
			s+="0";
		}
		else{
			while(ans<bei){
			ans*=2;
		}
		if(ans!=bei){
			ans/=2;
		}
		while(ans!=0){
			if(bei<ans){
				s+="0";
				ans/=2;
				continue;
			}
			s+="1";
			bei-=ans;
			ans/=2;
		}
		}
		int answer=-1,ui;
		for(int i=1;i<=n;i++){
			ui=and2(a[i]);
			answer=max(ui,answer);
		}
		cout<<answer;
		return 0;
	}
	if(flag==0&&n>3005){
		int mintwo=1e18+5,minx=1e18+5;
		for(int i=1;i<=n;i++){
			minx=min(minx,a[i]);
			int nowc=a[i];
			while(nowc){	
				if(nowc==1){
					mintwo=min(mintwo,nowc);
				}
				if(nowc%2==1){
					break;
				}
				nowc=nowc/2;
			}
		}
		if(minx<mintwo){
			cout<<0;
		}
		else{
			cout<<mintwo;
		}
		return 0;
	}
	dfs(1,0,0);
	cout<<maxn;
 	return 0;
}
