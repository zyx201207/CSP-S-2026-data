#include<bits/stdc++.h>
using namespace std;
string a;
int len,ans=0,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
	int num,q;
	cin>>num>>q;
	for(int j=1;j<=num;j++)a+=q;
    }
    len=a.size();
    a=' '+a;
    for(int i=1;i<=len/2;i++){
	if(a[i]!=a[len-i+1])ans++;
    }
    cout<<ans;
    return 0;
}
