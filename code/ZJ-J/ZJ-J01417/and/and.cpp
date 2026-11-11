#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
	int a;
	int tw[35];
	int k;
}number[200005];
bool cmp(node x,node y){
	return x.a>y.a;
}
int pow(int x){
	int s=1;
	while(x--){
		s<<=1;
	}
	return s;
}
int vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>number[i].a;
		int x=number[i].a;
		number[i].k=0;
		while(x){
			number[i].k++;
			number[i].tw[number[i].k]=x%2;
			x/=2;
		}
//		for(int j=number[i].k;j>=1;j--)cout<<number[i].tw[j];
//		cout<<"\n";
	}
	sort(number+1,number+n+1,cmp);
	for(int i=number[m].k;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)if(number[j].tw[i]&&!vis[j])cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++)if(!number[j].tw[i])vis[j]++;
			ans+=pow(i-1);
		}
	}
	cout<<ans;
	return 0;
}