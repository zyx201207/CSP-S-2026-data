#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M=3e5+10;
int n,m;
int b[N];
struct Node{
	int f;
	int ans;
}a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >>n >>m;
	for(int i = 1;i <= n;i++){
		cin >> b[i];
	}
	for(int i = 1;i <= m;i++){
		a[i].f = 0;
		a[i].ans = 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[b[j]].f == 1){
				for(int k = 1;k <= m;k++){
					a[k].f = 0;
				}
			}
			a[b[j]].f = 1;
		}
		for(int j = 1;j <= m;j++){
			if(a[j].f==1)a[j].ans++;
			a[j].f = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout <<a[i].ans <<' ';
	}
	return 0;
}