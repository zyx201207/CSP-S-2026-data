#include<bits/stdc++.h>
using namespace std;
const int N=500005;

int c,n,m,d,q,x,y;
long long wt[N];
vector<pair<int,int> > e[N];
vector<pair<int,int> > st[N];
struct node{
    int id;
    int l;
    int tot;
    bool operator <(const node &b)const{
        return tot<b.tot;
    }
};

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
	}
	for(int i=1;i<=n;i++){
		int num,a[N];
		cin>>num;
		for(int j=1;j<=(2*num);j++){
			cin>>a[j];
		}
		for(int j=1,k=1;j<=num*2-3;j+=2,k++){
			e[a[k]].push_back({i,a[j+2]});
			st[a[k]].push_back({i,a[j+1]});
		}
	}
    while(q--){
        cin>>x>>y;
    }
    return 0;
}

