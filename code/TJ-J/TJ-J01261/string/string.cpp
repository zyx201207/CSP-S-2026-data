#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	long long b,e;
	char c;
}a[N],re[N];
int n,cnt;
long long len,idx=1;
long long ans;
long long solve(int x,int y){
	if(a[x].c==re[y].c) return 0;
	if(a[x].b>=re[y].b and a[x].e<=re[y].e) return a[x].e-a[x].b+1;
	if(a[x].b<=re[y].b and a[x].e>=re[y].e) return re[y].e-re[y].b+1;
	if(a[x].e>re[y].e) return re[y].e-a[x].b+1;
	if(a[x].e<=re[y].e) return a[x].e-re[y].b+1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>a[i].c;
		a[i].b=idx;
		a[i].e=idx+len-1;
		idx+=len;
	}idx--;
	for(int i=1;i<=n;i++){
		if(a[i].b>(idx+1)/2) break;
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		re[cnt-i+1].e=idx-a[i].b+1;
		re[cnt-i+1].b=re[cnt-i+1].e-(a[i].e-a[i].b);
		re[cnt-i+1].c=a[i].c;
	}int i=cnt,j=1;
	while(i<=n and j<=cnt){
		if(a[i].e<=(idx+1)/2){
			i++;
			continue;
		}
		ans+=solve(i,j);
		if(a[i].e==re[j].e){
			i++;
			j++;
		}else if(a[i].e>re[j].e) j++;
		else i++;
	}cout<<ans;
	return 0;
}
