// wocaoweishazhongwenxianshibuchulaia
// Only feels like nothing could be better when I'm with you with you
// Dancing all night houmianbuhuichangle
/*
X X XXX
O O OOO
XX X XXX
OO O OOO
X X X XXXX
O O O OOOO
XX XX XX XXX
OO OO OO OOO
XXX
OOO
XXX X
OOO O
XXX XXX
OOO OOO
XX X X X
OO O O O
XXXXXXX
OOOOOOO
XXOOXXOOXXOOXXOOXXOOXXOOXXOOXXOO
XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO

luogu uid:1824569
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans=-1;
void dfs(int m,int cnt){
	if(m<=0) return ;
	if(cnt<=0) return ;
	sort(a+1,a+n+1);
	long long x=0;
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]){
			if(a[i-1]!=a[i]){
				x+=2;
			}else x++;
		}else{
			x=0;
		}
		ans=max(ans,x);
	}
	dfs(m,cnt-1);
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(m-1,cnt-1);
	}
}
int main(){     
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=0;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(i*(i+1)/2-1>m){
				cout<<i-1;
				return 0;
			}
			if(i*(i+1)/2-1==m){
				cout<<i;
				return 0;
			}
		}		
	}
	bool flag2=1;
	int k=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]!=a[i]+k) flag2=0;
	}
	if(flag2){
		for(int i=1;i<=n;i++){
			if((a[2]-a[1])*(i*(i+1)/2-1)>m){
				cout<<i-1;
				return 0;
			}
			if((a[2]-a[1])*(i*(i+1)/2-1)==m){
				cout<<i;
				return 0;
			}
		}
	}
//	dfs(m,n);
	for(int st=1;st<=n;st++){
		int lst=0,lsti=0;
		for(int i=st;i<=n;i++){
			lst=0;
			long long tmpp=0x3f3f3f3f;
			for(int st2=1;st2<=n;st2++){
				long long tmp;
				for(int j=st2;j<i;j++){
					tmp=a[i]-a[j];
					tmpp=min(tmp,tmpp);
				}
				if(m-tmpp<0){
					cout<<i-1-st2;
					return 0;
				}			
				m-=tmpp;	
			}

		}   		
	}
}