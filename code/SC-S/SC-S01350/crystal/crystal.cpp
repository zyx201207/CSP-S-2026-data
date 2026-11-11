#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
struct node{
	long long a;
	int appear=0;
}sex[MAXN];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,maxnum=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sex[i].a;
	}
	sort(sex+1,sex+n+1,cmp);
	int cnt=1,tap=1;
	for(int i=1;i<=n;i++){
		if(sex[i].a!=sex[i+1].a){
			for(int j=tap;j<=i;j++){
				sex[j].appear=cnt;
			}
			cnt=1;
			tap=i+1;
		}
		else	cnt++;
	}
	for(int tag=1;tag<=n;tag++){
		long long mp=m;
		int num=0;
		for(int i=1;i<=n;i++){
			if(i!=tag){
				if(mp>=tag-sex[i].a&&sex[i].a<tag){
					mp-=(tag-sex[i].a);
					num++;
				}
			}
		}
//		cout<<tag<<" "<<num<<" "<<sex[tag].appear<<"\n";
		maxnum=max(maxnum,num+sex[tag].appear);
	}
	cout<<maxnum;
	return 0;
}