#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010];//,d[400010];
char c[200010];
vector<pair<long long,bool> > v;

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n+1-i]=a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	v.push_back(make_pair(0ll,0));
	int l=1,r=1;
	while(l<=n || r<=n){
		if(a[l]>b[r]){
			pair<long long,bool> p=make_pair(b[r],c[l]==c[n+1-r]);
			v.push_back(p);
			r++;
		}
		else if(a[l]<b[r]){
			pair<long long,bool> p=make_pair(a[l],c[l]==c[n+1-r]);
			v.push_back(p);
			l++;
		}
		else{
			pair<long long,bool> p=make_pair(a[l],c[l]==c[n+1-r]);
			v.push_back(p);
			l++;r++;
		}
	}
	long long cnt=0;
	for(int i=1;i<v.size();i++){
		pair<long long,bool> p=v[i];
		if(p.second==0){
			pair<long long,bool> q=v[i-1];
			cnt+=p.first-q.first;
		}
	}
	cout<<cnt/2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//while (1){
		solve();
	//}
	return 0;
}
