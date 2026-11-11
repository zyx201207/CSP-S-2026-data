#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x;
	int cnt=0;
	friend bool operator < (node xx,node yy){
		if(xx.cnt==yy.cnt){
			return xx.x>yy.x;
		}
		return xx.cnt>yy.cnt; 
	}
}a[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		int t=a[i].x;
		while(t){
			if(t%2){
				a[i].cnt++;
			}
			t/=2;
		}
	}
	sort(a+1,a+n+1);
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
