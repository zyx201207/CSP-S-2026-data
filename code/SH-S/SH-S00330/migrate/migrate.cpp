# include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long ans=0,d,xxs=0,x[2000010],mi=1e18+10,mis=0;
void f(int xx,int xs,int z,int k){
	if (xx>z){return;}
	if (xs==z){
		if (k<mi){
			mis=1;
			mi=k;
		}
		else{mis++;}
	}
	if (x[xx+1]-x[xs]<=d){
		f(xx+1,xx+1,z,k+1);
		f(xx+1,xs,z,k);
	}
	else{return;}
}
int main(){
	freopen("migrate.in","r",stdin);// 
	freopen("migrate.out","w",stdout);// 
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}
		ans=0;
		bool ffx=1;xxs=x[2]-x[1];
		for (int i=3;i<=n;i++){
			if (x[i]-x[i-1]!=xxs){
				ffx=0;break;
			}
		}
//		if (ffx==1){
//			for (int i=2;i<=d/xxs;i++){
//				ans+=(n-i*2+1);
//			}
//			cout << ans << endl;
//			continue;
//		}
		
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				mi=1e9+10;mis=0;
				f(i,i,j,0);
				if (mis==2){
					ans++;
				}
				if (mis>0){
					// cout << ans << ' ' << i << ' ' << j << ' ' << mis << ' ' << mi << endl;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
