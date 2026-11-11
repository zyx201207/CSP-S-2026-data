#include <bits/stdc++.h>
using namespace std;
long long energy[500002];
int n;long long m;
long long base;
int total;
long long need_change;
const bool dbg = false;
bool cmp(int a,int b){
	return abs(b-base) > abs(a-base);
}
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> energy[i];
	}
	base = energy[int(n/2.0+0.5)];
	if(dbg) cout << "Base:" << base << '\n';
	sort(energy+1,energy+1+n,cmp);
	for(int i = 1;i <= n;i++){
		need_change = abs(energy[i]-base);
		if(dbg) cout << "need change:" << need_change << endl;
		if(m >= need_change){
			m -= need_change;
			total++;
		}else{
			break;
		}
	} 
	cout << total;
	return 0;
} 
