#include<bits/stdc++.h>
using namespace std;
int n,m,andn=INT_MAX,tmp;
int a[200086],cnt[40];
bool cmp(int x,int y){
	if((x/tmp)%2==(y/tmp)%2)return x>y;
	return (x/tmp)%2>(y/tmp)%2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmpi=a[i];
		for(int i=0;i<=30;i++){
			cnt[i]+=tmpi%2;
			tmpi/=2;
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			tmp=pow(2,i);
			break;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)andn&=a[i];
	cout<<andn;
	return 0;
}