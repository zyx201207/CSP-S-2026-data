#include<bits/stdc++.h>
using namespace std;
long long ans,m[100000001],n,sum,g,w; 
char s[100000001];
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> m[i] >> s[i];
		ans+=m[i];
		g = ans-m[i];
		for(int j = 1;j<=ans;j++){
			a[j+g] = s[i];
		}
	}
	for(int i = 1;i<=ans/2;i++){
		w = ans-i;
		if(a[w]!=a[i]){
			a[w] = a[i];
			sum++;
		}
		
	}
	cout << sum;
    return 0;
}