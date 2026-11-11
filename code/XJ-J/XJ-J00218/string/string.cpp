#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin >> a;
	int ti[a],tis=0,toe=a-1,tos=0,tie=a-1;
	long long ans=0;
	string to[a];
	for (int i = 0;i < a;i++){
		cin >> ti[i] >> to[i];
	}
	for (int j = 1;j < a;j++){
		if(ti[tis] < ti[tie]){
			if(to[tos] != to[toe]){
				ans += ti[tis];
			}
			ti[toe] -= ti[tis];
			tis += 1;
			tos += 1;
		}else if(ti[tis] > ti[tie]){
			if(to[tos] != to[toe]){
				ans += ti[tie];
			}
			ti[tis] -= ti[tie];
			tie -= 1;
			toe -= 1;
		}else if(ti[tis] = ti[tie]){
			if(to[tos] != to[toe]){
				ans += ti[tis];
			}
			tie -= 1;
			toe -= 1;
			tis += 1;
			tos += 1;
			j++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
