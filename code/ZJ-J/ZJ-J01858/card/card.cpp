#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ans[N],cp[N];
vector<int> b[M];

struct od{
	int order,num;
}ord[N];

bool cmp(od l,od r) {return l.order<r.order;}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++) ord[i].num=i,ord[i].order=b[i][0];
	for(int i=1;i<=n;i++){
		if(i!=1) {
			cp[a[i-1]]++;
			for(int j=1;j<=m;j++) 
				if(ord[j].num==a[i-1])
					ord[j].order=b[a[i-1]][cp[a[i-1]]];
		}
		sort(ord+1,ord+m+1,cmp);
//		for(int i=1;i<=m;i++) cout<<ord[i].num<<" "<<ord[i].order<<"\n"; cout<<"\n";
		int maxx=0;
		for(int j=1;j<=m;j++) {
			int l=b[ord[j].num].size();
			if(b[ord[j].num][l-1]>maxx) {
				ans[ord[j].num]++,maxx=b[ord[j].num][l-1];
//				cout<<ord[j].num<<" ";
			}
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	  
	return 0;
}
