#include<bits/stdc++.h>
using namespace std;
int n,m,pos;
int a[500005],cnt[400005];
vector<int> v,ls;
bool find(int x){
	for(int i=0;i<(int)v.size();i++){
		if(v[i]==x){
			pos=i;
			return true;
		}
	}
	return false;
}
void v_erase(){
	for(int i=0;i<pos;i++){
		ls.push_back(v[i]);
	}
	v.clear();
	for(int i=0;i<(int)ls.size();i++){
		v.push_back(ls[i]);
	}
	ls.clear();
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;++j){
			if(find(a[j])){
				v_erase();
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<(int)v.size();j++){
			cnt[v[j]]++;
		}
		v.clear();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}