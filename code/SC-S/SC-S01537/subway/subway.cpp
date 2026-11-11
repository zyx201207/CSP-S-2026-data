#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q,w[N];
struct node{
	int k;
	vector<int> a;
	vector<int> t;
}v[510];
struct kl{
	int s,e;
}o[100010]; 
int tong[N];
vector<int> duo;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 0; i<m; i++){
		cin>>w[i];
	}
	for(int i = 0; i<n; i++){
		cin>>v[i].k;
		for(int j = 0; j<v[i].k; j++){
			int a,t;
			cin>>a>>t;
			v[i].a.push_back(a);
			v[i].t.push_back(t);
			tong[a]++;
		}
	}
	for(int i = 0; i<q; i++){
		cin>>o[i].s>>o[i].e;
	}
	for(int i = 0; i<q; i++){
		long long ans = 0;
		ans += w[o[i].s - 1];
		long long mx = LLONG_MAX;
		for(int j = 0; j<n; j++){
			long long temp = 0;
			bool flag = false;
			bool f = false;
			for(int k = 0; k<v[j].k; k++){
				if(v[j].a[k] == o[i].s){
					temp += v[j].t[k]; 
					f = true;
				}
				if(v[j].a[k] != o[i].s)
					temp += v[j].t[k];
				if(v[j].a[k] == o[i].e && f){
					flag = true;
					break;
				}
			}
			if(!flag){
				temp = LLONG_MAX;
			}
			mx = min(temp,mx);
		} 
		if(mx == LLONG_MAX){
			for(int i = 1; i<=m; i++){
				if(tong[i] > 1){
					duo.push_back(i);
				}
			}
			
		}
		ans += mx;
		ans += w[o[i].e - 1];
		cout<<ans<<endl;
	} 
	return 0;
} 