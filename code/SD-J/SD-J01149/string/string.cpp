#include<bits/stdc++.h>
using namespace std;
const int d=2e5;
long long n,a[d+5];
long long cnt=0,i=1,j,zuo=0,you=0;
char c[d+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	j=n;
	zuo=a[i],you=a[j];
	while(i<j){
		if(c[i]!=c[j]){
			cnt+=min(zuo,you);
		}
		if(zuo<you){
			you-=zuo;
			zuo=a[++i];
		}
		else if(zuo==you){
			zuo=a[++i],you=a[--j];
		}
		else{
			zuo-=you;
			you=a[--j];
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
