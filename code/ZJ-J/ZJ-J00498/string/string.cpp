#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e8+5;
int n,ans,tmp=1;
int a;
char c;
char ss[MAXX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(int j=1;j<=a;j++){
			ss[tmp]=c;
			tmp++;
		}
	}
	int l=1,r=tmp-1;
	while(l<=r) {
		if(ss[l]!=ss[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}