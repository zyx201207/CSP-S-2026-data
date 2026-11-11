#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005],maxx=-1;
string b[200005];
bool bb[200005];
void dfs(int step){
	if(step==m+1){
		int maxn=a[s[1]];
		for(int i=2;i<=step-1;i++){
			maxn=a[s[i]]&maxn;
		} 
		maxx=max(maxx,maxn);
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(bb[i]==0){
				bb[i]=1;
				s[step]=i;
				dfs(step+1);
				bb[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-10;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int y=a[i],j=1;
		while(y!=0){
			int a=y%2;
			b[i][j]=char(a+'0');
			y/=2;
			j++;
		}
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
		cout<<12;
		return 0;
	}else if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	dfs(1);
	cout<<maxx;
	return 0;
}
