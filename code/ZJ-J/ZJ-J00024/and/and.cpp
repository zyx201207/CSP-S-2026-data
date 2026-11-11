#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	// freopen("E:\\cspj\\down\\and\\and5.in","r",stdin);
	// freopen("E:\\cspj\\down\\and\\and5.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>lst;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst.push_back(i);
	}
	for(int i=29;i>=0;i--){
		vector<int>tmp;
		for(int j=0;j<lst.size();j++){
			if((a[lst[j]]>>i)&1){
				tmp.push_back(lst[j]);
			}
		}
		if(tmp.size()>=m){
			lst=tmp;
		}
	}
	int ans=a[lst[0]];
	for(int i=1;i<m;i++){
		ans=(ans&a[lst[i]]);
	}
	cout<<ans;
	return 0;
}