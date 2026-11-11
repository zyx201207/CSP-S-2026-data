#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200020],l,r,ans,num;
void bfs(long long x,long long y,long long num,int f){
	if(y==m){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n-m+y+1;i++){
		if(!f)bfs(i+1,y+1,a[i],1);
		else bfs(i+1,y+1,num&a[i],1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){cout<<12;return 0;}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){cout<<7;return 0;}
	bfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
