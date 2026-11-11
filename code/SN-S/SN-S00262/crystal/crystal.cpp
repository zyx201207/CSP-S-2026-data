#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define int long long
int n,m,a[500050],s[500050];
bool cA(){
	int r=a[2]-a[1];
	for(int i=1;i<n;i++) if(a[i+1]-a[i]!=r) return 0;
	return 1;
}
bool cha(int i){
	int cc=0;
	for(int j=1;j<=i;j++)cc+=abs(a[j]-a[i]);
	if(cc<=m) return 1;
	return 0;
}
#define int int
int main(int argc, char** argv) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	#define int long long
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+i;
	}
	sort(a+1,a+n+1);
	if(cA()){
		int r=a[2]-a[1];
		int f=m/r+1,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]<=f) cnt++;
			else break;
		}
		cout<<cnt;
		return 0;
	}
	int mx=-1;
	for(int i=1;i<=n;i++){
		if(!cha(i)) break;
		else mx=max(mx,i);
	} 
	cout<<mx;
	return 0;
}
