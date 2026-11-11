#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	int a;
	char c;
}a[200009];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int ans=0;
	for(int i=1,j=n;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].a<a[j].a){
				a[j].a-a[i].a;
				a[i].a=0;
				i++;
			}
			else if(a[i].a>a[j].a){
				a[i].a-a[j].a;
				a[j].a=0;
				j--;
			}
			else{
				a[i].a=0;
				a[j].a=0;
				i++;
				j--;
			}
		}
		else{
			if(a[i].a>a[j].a){
				a[i].a-a[j].a;
				ans+=a[j].a;
				a[j].a=0,a[j].c=a[i].c;
				j--;
			}
			else if(a[i].a<a[j].a){
				a[j].a-a[i].a;
				ans+=a[i].a;
				a[i].a=0,a[i].c=a[j].c;
				i++;
			}
			else{
				ans+=a[i].a;
				a[j].a=0;
				a[i].a=0,a[i].c=a[j].c;
				i++;
				j--;
			}
		}
	}
	if(n%2!=0){
		ans--;
	}
	cout<<ans;
	return 0;
}
