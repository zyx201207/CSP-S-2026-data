//Kong Chenfeng xi'an shi han guang zhong xue SN-J00666
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn],b[maxm],c[maxn];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				auto it=v.begin()+b[a[j]]-1;
				v.erase(it,v.end());
				v.push_back(a[j]);
				b[a[j]]=v.size();
			}else{
				v.push_back(a[j]);
				b[a[j]]=v.size();
			}
		}
		for(int j=0;j<v.size();j++){
			c[v[j]]+=(v[j]==0?0:1);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

