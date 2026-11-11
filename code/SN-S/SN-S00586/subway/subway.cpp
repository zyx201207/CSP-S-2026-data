#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[500][100000],k1[500][100000],p[100000];
int f1(int i,int x,int y){
	int cnt=0;
	for(int j=0;j<q;j++){
		cnt+=k1[i][j];
		if(k[i][j]==y){
			return cnt;
		}
	}
}
int f(int x,int y){
	int a[q],max1;
	for(int i=0;i<q;i++){
		if(p[i]==x){
			a[i] = f1(i,x,y);
		}
	}
	for(int i=0;i<q-1;i++){
		if(a[i]<a[i]+1&&a[i]!=0){
			max1 = a[i];
		}
	}
	return max1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int w[m],x[q],y[q],cnt[q];
	for(int i=0;i<m;i++){
		cin >> w[i];
	}
	for(int i=0;i<n;i++){
		cin >> p[i];
		for(int j=0;j<q;j++){
			cin >> k[i][j] >> k1[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin >>x[i] >> y[i];
	}
	for(int i=0;i<q;i++){
		cnt[i] = f(x[i],y[i]);
	}
	for(int i=0;i<q;i++){
		cout << cnt[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
