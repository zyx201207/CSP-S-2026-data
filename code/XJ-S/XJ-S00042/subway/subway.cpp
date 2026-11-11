#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m+1),ans(q,0);
	vector<int> xian(m+1,0);
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int b;
		cin >> b;
		for(int j=0;i<b;i++){
			int zhandian,shijian;
			cin >> zhandian >> shijian;
			xian[zhandian]+=shijian;
		}
	}
	for(int r=0;r<q;r++){
		int qi,zhong;
		cin >> qi >> zhong;
		ans[r]+=w[qi];
		ans[r]+=xian[qi+zhong]/2;
		ans[r]+=w[zhong];
	}
	for(int i=0;i<q;i++){
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
