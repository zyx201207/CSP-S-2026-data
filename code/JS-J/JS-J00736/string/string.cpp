#include<bits/stdc++.h>
using namespace std;
long long n;
struct te{
	int m;
	char s;
}a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].s;
        if(a[i].s!=a[i-1].s) flag=0;
	}
	if(flag==1){
        cout<<0<<endl;
        return 0;
	}
	return 0;
}
