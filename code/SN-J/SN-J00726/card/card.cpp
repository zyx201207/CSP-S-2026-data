//王宁远 西安辅轮中学 SN-J00726
#include<bits/stdc++.h>
using namespace std;
int n,b[200005],d[200005],k=1;
int sum=0;
char a[200005],c[200005];
int main(){
    string s;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}for(long long i=n;i>=1;i++){
	    c[k]=a[i];
		d[k]=b[i];
		k++;	
	}for(long long i=1;i<=n/2+1;i++){
	    if(c[k]!=a[k]) sum+=b[k];	
	}
	cout<<sum;
}

