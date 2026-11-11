#include<bits/stdc++.h>
using namespace std;
struct str{
	int num;
	char s;
}a[200005];
int n,cnt,n1;
string ans;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].s;
	}
	
	for(int i=0;i<n;i++){
		//for(int j=0;j<a[i].num;j++) ans+=a[i].s;
		n1+=a[i].num;
	}
	
	for(int i=0;i<n1;i++){
		//cout<<ans[i]<<' '<<ans[n1-1-i]<<endl;
		if(a[i].s!=a[n-i-1].s) cnt+=abs(a[i].num=a[n-i-1].num);
	}
	
	cout<<cnt;
	
	return 0;
}
