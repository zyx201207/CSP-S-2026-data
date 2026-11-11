#include<iostream>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			cin>>u>>v;
		}
		int m=(n-1)/2+1;
		int e=m/3;
		if(k==m){
			cout<<"1\n";
			continue;
		}
		int y=(k-1)/2+1;
		int t=e+1-y;
		cout<<t+1<<"\n";
//		cout<<m-k<<"\n";
	}
	return 0;
}
/*


0 1
21 4
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
1 12
2 13
3 14
4 15
5 16
6 17 
7 18
8 19
9 20
10 21


3


*/
