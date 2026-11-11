#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
long long n,m,a[N],b[N],cnt;
vector<int> e[N];
void slove(int x){
	cnt=0;
	for(int i=x;i<=n;i++){
		for(int j=cnt;j>=1;j--){
			if(a[i]==b[j]){
				cnt=j-1;
				break;
			}
		}
		b[++cnt]=a[i];
	}
	for(int i=1;i<=cnt;i++){
		cout<<b[i]<<" ";
	}
	cout<<"\n";
	return;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		slove(i);
	}
	return 0;
}
/*
7 4
2 3 1 4 1 4 2
10 3
1 3 2 2 2 1 3 2 2 1
10 3
3 1 2 1 3 2 3 1 2 1
*/
