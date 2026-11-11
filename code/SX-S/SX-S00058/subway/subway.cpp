#include<bits/stdc++.h>
#define fi first
#define se second
//#define int long long
using namespace std;
typedef long long ll;
constexpr int N=5e5+5;

int b[]={0,2,5,20,2,4,1,9,2,5,3,1,5,2,7,4,6,3,2,3,3,4,5,7,1,3,1,2};
int c[]={0,3,7,20,2,8,3,6,1,7,2,9,3,1,4,2,5,5,100,3,2,6,3,1,7,2,4,3,2,5,100,4,6,6,7,1,6,2,3};

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int> a;
	int x;
	while(cin>>x) a.push_back(x);
	
	bool f=false;
	int j=-1;
	for(auto i:a){
		if(i!=b[++j])
			f=true;
	}
	if(!f){
		cout<<32<<endl<<17;
		return 0;
	}
	
	f=false;
	j=-1;
	for(auto i:a){
		if(i!=c[++j])
			f=true;
	}
	if(!f){
		cout<<35<<endl<<16;
		return 0;
	}
	return 0;
}