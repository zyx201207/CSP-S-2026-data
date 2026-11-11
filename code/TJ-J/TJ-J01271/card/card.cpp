#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int> a,b;
bool qwe(int r[];int y){
	for(int i=0;i<r.size();i++){
		if(r[i]==y){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	return 0;
}
