#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
vector<vector<int> > re(31);
int ans=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a_;
		cin >> a_;
		a.push_back(a_);
	}
	sort(a.begin(),a.end());
	
	//deal the number in "2Jin Zhi"
	for(int i=0;i<n;i++){
		int a_=a[i];
		int li=1;
		while(a_){
			if(a_&1)re[li].push_back(a_);
			a_=a_>>1;
			li++;
		}
	}
	
	for(int i=30;i>0;i--){
		if(re[i].size()>=m){
			ans=re[i][0];
			for(int j=1;j<=m;j++){
				ans=ans&re[i][j];
			}
			break;
		}
	}
	cout << ans;
	return 0;
}