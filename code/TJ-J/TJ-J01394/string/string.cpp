#include<bits/stdc++.h>
using namespace std;
string a;
int c[1000000];
string b;
int d[1000000];
int n;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	int p=1; 
	for(int i=1;i<=n;i++){
		cin>>c[i]>>b[i];
		while(c[i]!=0){
			a[p]=b[i];
			c[i]--;
			p++;
		}
	}
	int o=1;
	int u=0;
	int biaoji=1; 
	for(int i=p-1;i>=1;i--){ 
	if(p>i){
		if(a[i]!=a[o]){
			biaoji=0;
			u++;
		}
		o++;
	}
	}
	if(biaoji==1){
		cout<<0;
		return 0;
	}
    cout<<u;
    
}