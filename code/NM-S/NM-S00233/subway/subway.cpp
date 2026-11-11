#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c = 0,n = 0,m = 0,d = 0,q = 0;
	scanf("%i%i%i%i%i",&c,&n,&m,&d,&q);
	vector<int > vec1;
	vec1.push_back(0);
	for(int i = 1;i<=m;i++){
		int t = 0;
		scanf("%i",&t);
		vec1.push_back(t);
	}
//	vector< vector<int> > zhan(500005);
	int zhan[505][505] = {};
	long long s = 1;
	for(int i  = 1;i<=n;i++){
		int t1 = 0;
		cin>>t1;
		for(int j = 1;j<=t1;j++){
			int x = 0,y = 0;
			cin>>x>>y;
			zhan[s][x] = y;
//			cout<<zhan[j][x]<<" ";
		}
		s++;
	}
//	for(int i = 1;i<=2;i++){
//		for(int j = 1;j<=5;j++){
//			cout<<zhan[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i  =0 ;i<q;i++){
		long long k1 = 0;
		int b = 0,e = 0;
		scanf("%i%i",&b,&e);
		k1+=vec1[b]+vec1[e];
//		cout<<k1;
		bool f = 0;
		int x = b;
		for(int j = 1;j<=q;j++){
			for(int k = x;k<=e;k++){
				k1+=zhan[j][k];
				if(k == e){
					f = 1;
					break;
				}  
//				cout<<k1;
				if(zhan[j][k+1] == 0 && zhan[j][e] == 0){
					k1+=zhan[j+1][k];
//					cout<<k1<<" ";
					x = k+1;
//					cout<<k;
					break;
				}
			}
			if(f == 1){
				break;
			}
		}
		printf("%lli\n",k1);
	}
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
