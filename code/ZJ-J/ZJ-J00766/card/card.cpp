#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cur[200005];
map<int,int>cc;
int lfind(int x,int start=1,int stop=n){
	for(int i=start;i<=stop;i++){
		if(cur[i]==x){
			return i;
		}
	}
	return -1;
}
void f(int x){
	int cnt=n;
	for(int i=x;i<=n;i++){
		memcpy(cur,a,sizeof(cur));
		int pp=lfind(a[i],x,cnt);
		if(pp==-1){
			cur[++cnt]=a[i];
		}else{
			cnt=pp;
		}
	}
	for(int i=x;i<=cnt;i++){
		if(cur[i]<=m)cc[cur[i]]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cc[i]<<" ";
	}
	cout<<endl;
	return 0;
}
