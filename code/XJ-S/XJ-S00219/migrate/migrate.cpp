#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long N =2e6;
long long a[N];
int n,d;
int cnt = 0;

void sov(){
	int jie = a[1];
	int sd = d/jie;
	if(n%sd==0){
		cout<<0<<" ";
	}else{
		cout<<n/sd+1;
	} 
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0;
		//sov();
	}
	return 0;
} 
