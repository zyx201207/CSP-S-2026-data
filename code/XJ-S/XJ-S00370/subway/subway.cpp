#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);

	int c,n,m,d,q,get_wm,ki,ai,ti;
	int at[ki][2];
	vector<int> v_wm;
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=0;i<m;++i){
		cin>>get_wm;
		v_wm.push_back(get_wm);
	}
	
	for(int i=0;i<n;i++){
		cin>>ki;
		for(int j=0;j<2*ki;++j){
			cin>>ai>>ti;
		}
	}
	
	
	
	
	
	
	return 0;
}
