#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200010
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=n;i--)
int a[maxn];
char c[maxn];
int same[maxn];
int n,tgt;
int in(){
	int k=0,neg=0;
	char ch=getchar();
	while(!isdigit(ch)){
		ch=getchar();
		if(ch==45)neg=1;
	}
	
	while(isdigit(ch)){
		ch=getchar();
		k=(k<<1)+(k<<3)+(ch^48);
	}
	return k;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]>>c[i];
	}
	if(n==1)cout<<0;
	else if(n==2){
		if(c[1]==c[2])cout<<0;
		else cout<<min(a[1],a[2]);
	}
	else{
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1])++tgt;
		}
		cout<<tgt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
