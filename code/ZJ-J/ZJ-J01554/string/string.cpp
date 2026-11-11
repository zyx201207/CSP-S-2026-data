#include <bits/stdc++.h>
using namespace std;
#define  fin(x)  freopen(x,"r",stdin)
#define  fout(x)  freopen(x,"w",stdout)
const int N=2e5+7;
long long num=0;
long long ltor[N],rtol[N];
int cd[N];//³¤¶È
char ch[N];
int n;
long long ans=0;
int main()
{
	fin("string.in");
	fout("string.out");
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d %c",&cd[i],&ch[i]);
		num=max<int>(num,cd[i]);
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	if (n==2){
		if (ch[1]==ch[2]){
			cout<<0;
		}
		else {
			cout<<min(cd[1],cd[2]);
		}
		return 0;
	}
	if (num<=1){
		for (int i=1;i*2<=n;i++){
			if (ch[i]!=ch[n+1-i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
 } 
 // pfdm
