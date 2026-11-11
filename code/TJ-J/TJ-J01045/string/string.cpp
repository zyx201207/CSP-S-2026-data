#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
using namespace std;
int n,cnt,maxx=-1;
//char c[30];
struct Node{
	int x;
	char y;
}c[200005];
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
		if(c[i].x>maxx)cnt=c[i].x;
	}
	x=c[1].y;
	for(int i=1;i<=n;i++){
		if(c[i].y!=x){
			cout<<cnt;
			return 0;
		}
	}
	cout<<0;
	return 0;
} 
