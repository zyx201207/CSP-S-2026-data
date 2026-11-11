#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],s1,s2,ans;
char b[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}for(int i=1,j=n;i-1<j+1;){
		if(s1<=s2){
			while(s1<=s2){
				if(b[i]!=b[j+1])ans+=(s2-s1)-max(0LL,s2-s1-a[i]);
				s1+=a[i++];
			}
		}else{
			while(s1>s2){
				if(b[i-1]!=b[j])ans+=(s1-s2)-max(0LL,s1-s2-a[j]);
				s2+=a[j--];
			}
		}
	}cout<<ans;
	return 0;
}
/*
3
 2 a
 2 b
 1 c

2
 2 a
 3 a

6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b


*/

