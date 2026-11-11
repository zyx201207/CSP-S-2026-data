#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans,l,r;
char c[N];
string s;
map<int,int> m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	printf("%d",ans);
	return 0;
}
