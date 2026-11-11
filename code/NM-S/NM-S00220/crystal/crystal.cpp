#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool gl=1;
bool dc=1;
long long cz,czz;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m%2==1){
		cout<<m/2+1<<endl;
	}else{
		cout<<m/2<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
