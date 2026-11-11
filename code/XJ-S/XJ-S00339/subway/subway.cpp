#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=500005;
int w[N];
struct node{
	int r,t;
}a[N];
struct travel{
	int start,end;
}b[N];
vector<vector<int> > v(N);
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int len=0;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		for(int j=0;j<s;j++){
			cin>>a[len].r>>a[len].t;
			len++;
		}
	}
	for(int i=0;i<len-1;i++){
		v[a[i].r].push_back(a[i+1].r);
		v[a[i+1].r].push_back(a[i].r);
	}
	for(int i=0;i<q;i++){
		int cnt=0;
		cin>>b[i].start>>b[i].end;
		for(int i=0;i<len-1;i++){
			cnt+=v[a[i].r][0];
		}
		cout<<cnt<<" ";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
