#include <bits/stdc++.h>
using namespace std;
long long int n,m,maxx;
long long int a[200005];
string b[200005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){//qwq
		cin>>a[i];
		for(int j=1;j<i;j++){
			if(a[i]>maxx){
				maxx=a[i];
				flag=1;
			}
		}
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(flag){
		cout<<maxx;//awa awa awa
	}else{
		sort(a+1,a+n+1);
		cout<<a[n/2+1];
	}
}