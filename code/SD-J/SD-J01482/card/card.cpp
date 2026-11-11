#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005];
queue<int> q;
int size;
int main(){
 	freopen("card.in","r",stdin);
   	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	b[i]=i;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=2;i<=n;i++){
    	if(a[i]!=a[i-1]){
    		cout<<b[i-1]<<" ";
		}
	}
	return 0;
} 
