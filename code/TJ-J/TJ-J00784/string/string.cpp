#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
namespace init{
	int n,cnt;
	int x[N],qzh[N];
	char y[N],s[N];
} 
using namespace init;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		qzh[i]+=qzh[i-1]+x[i];
	}
	for(int i=1;i<=qzh[n];i++) s[i]=' ';
	for(int i=1;i<=n;i++){
		s[qzh[i]]=y[i];
	}
	for(int i=1;i<=qzh[n];i++){
		if(s[i]==' '){
			for(int j=1;j<=n;j++){
				if(i<qzh[j]){
					s[i]=y[j];
					break;
				} 
			}
		}
	}
	for(int i=1;i<=qzh[n]/2;i++){
		if(s[i]!=s[qzh[n]-i+1]){
			cnt++;
		} 
	}
	cout<<cnt;
	return 0;
} 
