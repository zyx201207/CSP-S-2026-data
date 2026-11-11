#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pbi pair<bool,int>
#define vi void
using namespace std;

const int N=5e5+5,M=3e5+5;

int n,m,hd,pos;
int a[N],st[N],ans[M];
pbi li[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
//		cout<<"turn"<<i<<":\n";
		hd=i;
		pos=1;
		for(int j=1; j<=m; j++) {
			li[j]= {0,0};
		}
		while(hd<=n) {
//			cout<<hd<<' '<<pos<<' '<<a[hd]<<endl;

			if(li[a[hd]].first) {
				int u=li[a[hd]].second;
				for(int l=u+1; l<=pos; l++) {
					li[st[l]]= {0,0};
				}
				pos=u;
//				cout<<"*remove:"<<u+1<<'~'<<pos<<'\n';
			} else {
				li[a[hd]]= {1,pos};
				st[pos]=a[hd];
//				cout<<"!";
			}
//			for(int i=1; i<=pos; i++) {
//				cout<<st[i];
//			}
//			cout<<endl;
//			cout<<"table1:";
//			for(int i=1; i<=m; i++) {
//				cout<<li[i].first<<' ';
//			}
//			cout<<endl;
//			cout<<"table2:";
//			for(int i=1; i<=m; i++) {
//				cout<<li[i].second<<' ';
//			}
//			cout<<endl<<endl;
			hd++;
			pos++;
		}
		for(int i=1; i<pos; i++) {
			ans[st[i]]++;
		}
//		for(int i=1; i<=m; i++) {
//			cout<<ans[i]<<' ';
//		}
//		cout<<endl;
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

