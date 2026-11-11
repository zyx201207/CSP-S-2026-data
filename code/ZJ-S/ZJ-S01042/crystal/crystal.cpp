#include <bits/stdc++.h>
using namespace std;
struct node{
	int p;
	int c;
}a[500005];
bool cmp(node a,node b){
	return a.c<b.c;
}
int n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].p;
	int v,flag=1;
	for(int i=2;i<=n;i++){
		cin>>a[i].p;
		if(i==2){
			v=a[i].p-a[i-1].p;
		}
		if(a[i].p-a[i-1].p!=v){
			flag=0;
		}
	}
	if(flag==1){
		int an=(n+1)/2;
		for(int j=1;j<=n;j++){
			a[j].c=abs(a[j].p-a[an].p);
		}
		sort(a+1,a+n+1,cmp); 
		int t=m,cnt=0;
		for(int j=1;j<=n;j++){
			if(t<a[j].c){
				break;
			}
			cnt++;
			t-=a[j].c;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[j].c=abs(a[j].p-a[i].p);
		}
		sort(a+1,a+n+1,cmp); 
		int t=m,cnt=0;
		for(int j=1;j<=n;j++){
			if(t<a[j].c){
				break;
			}
			cnt++;
			t-=a[j].c;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

