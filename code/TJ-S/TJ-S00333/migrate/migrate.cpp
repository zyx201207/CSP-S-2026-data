#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while(T--){
		int n,d;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				int lin=cnt;
				bool f=0; 
				for(int z=i;z<j;z++) {
					if((a[z+1]-a[z])<=d){
						cnt++;
					} else {
						f=1;
						break;
					}
				}
				if(f){
					cnt=lin;
					continue;
				}
				if(cnt-lin>2)cnt=lin;
			}
		}
		cout << cnt;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/ 
