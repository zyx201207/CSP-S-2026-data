#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[1000][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int big=-1,id=0,ans=0;
	for(int i=0;i<m;i++){
		for(int j=id;j<n;j++){
			cnt[i][j];
			ans++;
		}
		id++;
	}
	for(int i=0;i<ans/m;i++){
		int lin=cnt[i][0];
		for(int j=0;j<m;j++){
			lin&=cnt[i][j];
		}
		if(lin>big)big=lin;
	}
	cout << big;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
