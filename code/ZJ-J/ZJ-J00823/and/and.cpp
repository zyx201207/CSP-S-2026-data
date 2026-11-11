#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long man[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> m >> n;
	for(long long i = 1;i <= m;i++){
		cin >> man[i];
	}
	sort(man+1,man+m+1,cmp);
	int ans = man[1];
	for(long long i = 1;i <= n;i++){
		if(i == n) cout << man[i] and ans;
		else ans and man[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}
