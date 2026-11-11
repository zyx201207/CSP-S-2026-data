#include<bits/stdc++.h>
using namespace std;
int n,m,q,e,maxn=0;
int a[100000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
	    if(m==2){
			q=a[i]&a[i+1];
			i++;
		}
		if(q>maxn){
			e=q;
		}
	}
	cout << e;
		return 0;
} 
 

    