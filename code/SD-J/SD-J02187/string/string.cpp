#include<bits/stdc++.h>
using namespace std;
int n;
long long tap,cnt=0,m=0;
char a[10000005],z; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tap>>z;
		for(int i=0;i<tap;i++){
			a[cnt]=z;
			cnt++;
		}
	}for(int i=0;i<cnt/2;i++){
		if(a[i]!=a[cnt-i-1]){
			m++;
		}
	}cout<<m;
	return 0;
}
