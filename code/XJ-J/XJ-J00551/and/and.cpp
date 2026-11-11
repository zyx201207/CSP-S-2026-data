#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
long long a[maxn];
long long b[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		for(int j=i;j>=0;j--){
			if(a[i]>=b[j]){
				b[j+1]=b[j];
				b[j]= a[i];
			}
		}
	}
	int j=0;
	for(int i=1;i<=m;i++){
		if(b[i]%2==0){
			j++;
		}
	}
	if(j==0 || j==m){
		
	}else{
		b[m-1]--;
	}
	cout << b[m-1];
    return 0;
}