#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,sum;
string zg;
struct fun{
	int h;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].c;
		for(int j=1;j<=a[i].h;j++){
			zg+=a[i].c;
		}
		sum+=a[i].h;
	}
	for(int i=0;i<=sum/2;i++){
		for(int j=sum-1;j>=sum/2;j--){
			if(zg[i]!=zg[j]) cnt++;
			i++;
		}
	}
	cout<<cnt;
	return 0;
} 
/*
aabbc
2 a
2 b
1 c
5/2   2
*/
