#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char>> v1(n); vector<pair<int,char>> v2(n);
	for (int i=0;i<n;i++){
		cin>>v1[i].first>>v1[i].second;
		v2[n-i-1] = v1[i];
	}
	int fs1=0, fs2=0;
	int i1=0,i2=0;
	long long ans = 0;
	while (i1<n&&i2<n){
		auto p1 = v1[i1], p2 = v2[i2];
		p1.first -= fs1; p2.first -= fs2;
		if (p1.first>p2.first) swap(p1,p2);
		fs1+=p1.first; fs2+=p1.first;
		if (p1.second!=p2.second) ans += p1.first;
		if (fs1>=v1[i1].first){
			fs1 -= v1[i1++].first;
		}
		if (fs2>=v2[i2].first){
			fs2 -= v2[i2++].first;
		}
	}
	cout<<ans/2<<endl;
}
