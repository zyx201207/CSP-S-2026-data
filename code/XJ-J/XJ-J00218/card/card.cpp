#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	cin >> n >> m;
	string to[n];
	int ti[n],cc[n],s[m],cs=0;
	for (int i = 1;i <= m;i++){
		s[i-1] = 0;
	}
	for (int i = 0;i < n;i++){
		cin >> cc[i];
		ti[i] = 0;
		to[i] = "t";
	}
	for (int p = n-1;p >= 0;p--){
		for (int i = 0;i <= p;i++){
			ti[i] = cc[cs+i];
			k = 0;
			for (int j = 0;j < i;j++){
				if (ti[j] == ti[i] && to[j] == "t"){
					k = 1;
				} 
				if(k == 1){
					to[j] = 'f';
				}
			}
			to[i] = 't';
		}
		for (int i = 1;i <= m;i++){
			for (int j = 0;j <= p;j++){
				if (ti[j] == i && to[j] == "t"){
					s[i-1] += 1;
				}
			}
		}
		cs += 1;
	}
	for (int i = 0;i < m;i++){
		cout << s[i];
		if (i < m-1){
			cout << ' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
