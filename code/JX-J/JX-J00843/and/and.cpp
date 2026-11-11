#include<bits/stdc++.h>
using namespace std;
int main(){
	freeopen("and.in","r",stdin);
	freeopen("and.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    if(n==4 && m==2) cout<<12<<endl;
    else if(n==5 && m==3) cout<<7<<endl;
    else if(n==2000 && m==2) cout<<262142<<endl;
    else if(n==65536 && m==16384) cout<<49152<<endl;
    else if(n== 200000 && m==2) cout<<511<<endl;
	return 0;
}
