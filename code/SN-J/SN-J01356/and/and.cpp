#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,inh,ans;
	int fl=-1,fla=-1,flag=-1;
	cin >> n >> m;
	
	if(m==1){
		for(int i=1;i<=n;i++){
			cin >> inh;
			ans = max(ans,inh);
		}
		cout << ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin >> inh;
		if (inh==1) fl++;
		if (inh==2) fla++;
		if (inh==3) flag++;
		if (fl>=1&&flag>=1&&fla>=1) break;
	}
	if(flag>=1) cout << 3;
	else if(fla>=1) cout << 2;
	else if(fl>=1) cout << 1;
	else cout << 0;
		
	return 0;
}

