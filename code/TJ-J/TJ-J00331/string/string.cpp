#include<bits/stdc++.h>
using namespace std;

//string max lrngth == 2*10^14 
int n,i;
long long tn[200010],tml=1;
long long ans = 0;
char tc[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> tn[tml] >> tc[tml];
		if(tc[tml-1] == tc[tml]){
			tn[tml-1] += tn[tml];
		}else{
			tml++;
		}
	}
	for(int i = 1;i < tml-1;i++){
		for(long long j = 0;j < tn[i];j++){
			cout << tc[i];
		}
	}
	cout << endl;
	int l = 1,r = tml-1;
	bool b = false;//is l max
	while(l < r){
		if(tc[l] == tc[r]){
			ans += abs(tn[l]-tn[r]);
			//cout << "ans += " << tn[l] << "-" << tn[r] << "/+" << abs(tn[l]-tn[r]) <<endl;//DEBUG 
			if(tn[l] == tn[r]){
				l++;
				r--;
				continue;
			}
			if(tn[l] < tn[r]) b = false;
			else b = true;
			if(b){
				tn[l] -= tn[r];//对长的进行分割
				r--;//删除短的
			}else{
				tn[r] -= tn[l];
				l++;
			}
		}else{
			ans += min(tn[l],tn[r]);
			if(tn[l] == tn[r]){
				l++;
				r--;
				continue;
			}
			if(tn[l] < tn[r]) b = false;
			else b = true;
			if(b){
				tn[l] -= tn[r];//对长的进行分割
				r--;//删除短的
			}else{
				tn[r] -= tn[l];
				l++;
			} 
		}
	}
	cout << ans;
	return 0;
}
