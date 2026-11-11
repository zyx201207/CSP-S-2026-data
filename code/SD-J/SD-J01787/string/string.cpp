#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+105;
int a[N];char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long cnt=0;
	int x,y,i=1,j=n;
	x=a[i],y=a[j];
	while(i<j){
		if(s[i]!=s[j]){
			cnt+=min(x,y);
		}
		if(x>y){
			a[j]=0,x-=y;j--;y=a[j];
		}else if(x==y){
			i++,j--;x=a[i],y=a[j];
		}else{
			a[i]=0,y-=x;i++;x=a[i];
		}
	}
	cout<<cnt;
	return 0;
}

