#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
int n,m;
vector<int> vec;
int cz(int x){
	for(int i=0;i<vec.size();i++){
		if(vec[i]==x) return i;
	}
return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int dq=a[j];
			int gg=cz(dq);
			if(gg==-1){
				vec.push_back(dq);
			}else{
				while(vec.size()!=gg) vec.pop_back();
			}
		}
		for(int j=0;j<vec.size();j++){
			t[vec[i]]++;
		}
		vec.clear();
	}
	for(int i=1;i<=m;i++) cout<< t[i] ;
	return 0;
}
