#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,m,a[200005];
string s1[200005];
struct node{
	string s;
	int x;
}str[200005];
struct node2{
	int ans,wi;
}vis[200005];
bool cmp(node x,node y){
	return x.s.size() > y.s.size();
}
bool cmp2(node2 x,node2 y){
	return x.ans > y.ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m == 1){
		long long smax = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			smax = max(smax,a[i]);
		}
		cout<<smax<<endl;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		int now = a[i];
		while(now!=0){
			if(now%2 == 1){
				str[i].s = "1"+str[i].s;
			}else{
				str[i].s = "0"+str[i].s;
			}
			now/= 2;
		}
		str[i].x = a[i];	
	}
	sort(str+1,str+n+1,cmp);
	int tp = str[m].s.size();
	for(int i = 0;i < tp;i++){
		for(int j = 1;j <= n;j++){
			string ssd = str[j].s;
			if(ssd[i] == '1'){
				vis[j].ans++;
			}
			vis[j].wi = j;
		}
	}
	sort(vis+1,vis+n+1,cmp2);
	int smax;
	int w = vis[1].wi;
	smax = str[w].x;
	for(int i = 2;i <= m;i++){
		w = vis[i].wi;
		smax = smax & str[w].x;
	}
	cout<<smax<<endl;
    return 0;
}
