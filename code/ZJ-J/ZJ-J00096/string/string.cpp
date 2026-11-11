#include <bits/stdc++.h>
using namespace std;

char a[20001];
int p[20001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int p1;
		char s;
		cin >> p1 >> s;
		a[i]=s;
		p[i]=p1;
	}
	long long i=1,j=n,num=0;
	while(i<j){
		if(a[i]!=a[j]){
			int o=min(p[i],p[j]);
			p[i]-=o;
			p[j]-=o;
			num+=o;
		}
		else{
			int o=min(p[i],p[j]);
			p[i]-=o;
			p[j]-=o;
		}
		if(!p[i]){
			i++;
		}
		if(!p[j]){
			j--;
		}
	}
	cout << num;
}
