#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,nl[100001];
	long long ns[10001],fs[100001];
	char ms[1001][1001],f[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ns[i];
		int cnt=0;
		while(ns[i]>0){
			cnt++;
			ms[i][cnt]=ns[i]%2;
			ns[i]=ns[i]/2;
		}
		nl[i]=cnt;
	}
    fclose(stdin);
    fclose(stdout);
}
