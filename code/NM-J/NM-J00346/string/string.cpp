#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
const int INF=0x3f3f3f3f;
int n,cnt;
char s[N];
struct str{
	int x;
	char c;
};
str a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		s[a[i].x]=a[i].c;
	}
	int l=1;
	int r=n+1;
	while(l<=r){
		if(l!=r){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
    return 0;
}
