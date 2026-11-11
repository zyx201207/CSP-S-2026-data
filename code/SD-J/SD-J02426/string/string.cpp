#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
string s;
int n,ans;
inline char bel(int pos){
	return s[pos];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int j=1;j<=a;j++)
			s+=c;
	}
	int mid=s.length()/2-1;
	for(int i=mid;i>=0;i--){
		if(bel(i)!=bel(s.length()-1-i)){
			ans++;
		}	
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
